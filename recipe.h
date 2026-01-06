#pragma once
#include <vector>
#include <string>

struct Recipe {
    std::string id;
    std::string title;
    std::vector<std::string> tags;
    std::vector<std::string> ingredients;
    std::vector<std::string> steps;
    int rating = 0;

};