#include <iostream>
#include "../external/httplib.h"

int main() {
    httplib::Server app;

    // This line connects C++ to your web folder
    app.set_mount_point("/", "./web");

    std::cout << "Server running at http://localhost:8080\n";
    app.listen("0.0.0.0", 8080);
    return 0;
}
