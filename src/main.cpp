#include <iostream>
#include "../external/httplib.h"
#include <vector>
#include <string>

std::vector<std::string> testRecipes = {"kimchi", "salmon", "chile"};

int main() {
    httplib::Server app;

    // This line connects C++ to your web folder
    app.set_mount_point("/", "./web");

    std::cout << "Server running at http://localhost:8080\n";
    app.listen("0.0.0.0", 8080);
    app.Get("/api/recipes", [](const httplib::Request&, httplib::Response& res) {
    std::string json = "[";

    for (size_t i = 0; i < testRecipes.size(); ++i) {
        json += "\"" + testRecipes[i] + "\"";
        if (i + 1 < testRecipes.size()) json += ",";
    }

    json += "]";
    res.set_content(json, "application/json");
});

    return 0;
}
