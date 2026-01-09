#include <iostream>
#include "../external/httplib.h"
#include "../include/recipe.h"
#include "../external/json.hpp"
using nlohmann::json;
#include <vector>
#include <string>

static std::string escapeJson(const std::string& s) {
    std::string out;
    for (char c : s) {
        if (c == '\"') out += "\\\"";
        else if (c == '\\') out += "\\\\";
        else out += c;
    }
    return out;
}

static std::string recipeToJson(const Recipe& r) {
    std::string j = "{";
    j += "\"id\":\"" + escapeJson(r.id) + "\",";
    j += "\"title\":\"" + escapeJson(r.title) + "\",";
    j += "\"calories\":" + std::to_string(r.calories) + ",";
    j += "\"rating\":" + std::to_string(r.rating) + ",";
    // ingredients
    j += "\"ingredients\":[";
    for (size_t i = 0; i < r.ingredients.size(); ++i) {
        j += "\"" + escapeJson(r.ingredients[i]) + "\"";
        if (i + 1 < r.ingredients.size()) j += ",";
    }
    j += "],";
    // steps
    j += "\"steps\":[";
    for (size_t i = 0; i < r.steps.size(); ++i) {
        j += "\"" + escapeJson(r.steps[i]) + "\"";
        if (i + 1 < r.steps.size()) j += ",";
    }
    j += "]";
    j += "}";
    return j;
}


int main() {
    httplib::Server app;

    // This line connects C++ to your web folder
    app.set_mount_point("/app", "./web");

    Recipe r1;
    r1.id = "100001";
    r1.title = "Spaghetti";
    r1.calories = 520;
    r1.ingredients = {"pasta", "tomato sauce", "garlic"};
    r1.steps = {"Boil pasta", "Make sauce", "Combine"};
    r1.rating = 5;

    std::vector<Recipe> demo = { r1 };

    app.Get("/api/recipes", [&](const httplib::Request&, httplib::Response& res) {
        std::string json = "[";
        for (size_t i = 0; i < demo.size(); ++i) {
            json += recipeToJson(demo[i]);
            if (i + 1 < demo.size()) json += ",";
        }
        json += "]";
        res.set_content(json, "application/json");
    });

    std::cout << "UI:  http://localhost:8080/app/\n";
    std::cout << "API: http://localhost:8080/api/recipes\n";
    app.Post("/api/recipes", [&](const httplib::Request& req, httplib::Response& res) {
    json j = json::parse(req.body, nullptr, false);
    if (j.is_discarded()) {
        res.status = 400;
        res.set_content(R"({"error":"Invalid JSON"})", "application/json");
        return;
    }

    Recipe r;
    r.id = std::to_string(demo.size() + 1); // simple id for now
    r.title = j.value("title", "");
    r.calories = j.value("calories", 0);
    r.rating = j.value("rating", 0);
    r.ingredients = j.value("ingredients", std::vector<std::string>{});
    r.steps = j.value("steps", std::vector<std::string>{});

    if (r.title.empty()) {
        res.status = 400;
        res.set_content(R"({"error":"Title required"})", "application/json");
        return;
    }

    demo.push_back(r);
    res.status = 201;
    res.set_content(json{{"ok", true}, {"id", r.id}}.dump(), "application/json");
});
    app.listen("0.0.0.0", 8080);
    return 0;
}