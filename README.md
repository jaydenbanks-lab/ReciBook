# Recipe Saver 🍽️

A C++ recipe management application with a web-based user interface.  
The backend is written in modern C++ using a vector-based data model, while the frontend is built with HTML, CSS, and JavaScript and served locally via a lightweight HTTP server.

This project was designed incrementally to practice **data modeling, file organization, API design, and UI integration**.

---

## Features

- Add new recipes
- View recipe details
- Edit existing recipes
- Delete recipes
- Persist recipes to disk (JSON file)
- Web-based UI served from a C++ backend
- Clean, modular project structure

**Planned / In Progress**
- Sort recipes by calories
- Filter recipes by tags
- Enhanced UI interactions

---

## Tech Stack

### Backend
- **C++17**
- `std::vector` for recipe storage
- Lightweight HTTP server
- JSON-based persistence

### Frontend
- HTML
- CSS
- JavaScript (vanilla)

---

## Project Structure

```
recipe-saver/
├── src/            # C++ implementation files
│   ├── main.cpp
│   ├── recipebook.cpp
│   └── server.cpp
│
├── include/        # C++ header files
│   ├── recipe.h
│   ├── recipebook.h
│   └── server.h
│
├── web/            # Frontend UI
│   ├── index.html
│   ├── style.css
│   └── app.js
│
├── data/
│   └── recipes.json
│
├── CMakeLists.txt
└── README.md
```

---

## Design Overview

- **Recipe**
  - Represents a single recipe and its data (title, ingredients, steps, rating, calories, etc.)
- **RecipeBook**
  - Manages a collection of recipes using a `std::vector`
  - Handles searching, adding, editing, deleting, and saving/loading
- **Server**
  - Exposes REST-style API endpoints
  - Serves the web UI and handles client requests
- **Web UI**
  - Communicates with the backend using HTTP requests
  - Displays and edits recipe data dynamically

This separation keeps **business logic, server logic, and UI concerns independent**.

---

## Building and Running

### Requirements
- C++17 compatible compiler
- CMake
- Git

### Build
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### Run
```bash
./recipe_saver
```

Then open your browser to:
```
http://localhost:8080
```

---

## Data Persistence

Recipes are saved to:
```
data/recipes.json
```

The application automatically loads recipes on startup and saves changes when recipes are added, edited, or deleted.

---

## Learning Goals

This project was created to practice:
- C++ class design and separation of concerns
- Vector-based data management
- Incremental feature development
- Basic REST API design
- Integrating a C++ backend with a web frontend
- Git version control and project organization

---

## Future Improvements

- Sorting recipes by calories
- Tag-based filtering
- Improved UI/UX (modals, recipe cards)
- Validation and error handling
- Unit tests for RecipeBook logic

---

## Author

**Jayden Banks**  
Computer Science Student  
Texas State University
