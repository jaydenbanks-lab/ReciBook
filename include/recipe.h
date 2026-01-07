#pragma once
#include <vector>
#include <string>

struct Recipe {
    std::string id; //to edit or delete entries
    std::string title;
    int calories = 0;

    std::vector<std::string> tags;
    std::vector<std::string> ingredients;
    std::vector<std::string> steps;
    int rating = 0;

};