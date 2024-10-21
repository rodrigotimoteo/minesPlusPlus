#include <iostream>
#include <string>

class Test {
private:
    std::string thisIsATest;

public:
    Test() : thisIsATest("new string") {
        std::cout << thisIsATest;
    }
};
