#include <iostream>
#include <string>

void print(const std::string & a)
{
    std::cout << a << std::endl;
}

int main() {
    std::string test = "aaa";
    print(test);
    return 0;
}