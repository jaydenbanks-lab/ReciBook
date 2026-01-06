#pragma once
#include "recipe.h"
#include <vector>
#include <string>
#include <optional>

class RecipeBook{
    private:
    std::vector<Recipe> recipes;

    public:
    const std::vector<Recipe>& getAll() const;
    std::vector<Recipe> searchByTitle(const std::string&) const;

    bool add(const Recipe&);
    bool removeById(const std::string& id);

    //std::optional<Recipe> getById(const std::string& id) const;

    bool loadFromFile(const std::string&);
    bool saveToFile(const std::string&) const;

};