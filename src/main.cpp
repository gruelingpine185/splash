#include <iostream>


int main() {
    try {

    } catch(const std::exception& _e) {
        std::cerr << _e.what() << std::endl;
    }

    return 0;
}
