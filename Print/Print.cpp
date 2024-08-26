#include <iostream>
#include <fstream>
#include <sstream>

template <typename... Args>
std::ostream& print(std::ostream& os, Args... data){
    ((os << data << " "),...);
    return os;
}

int main() {

    int num = 99;
    double pi = 3.14;
    std::string name = "Roberto";

    std::cout << "Output to std::cout:" << std::endl;
    print(std::cout, num, pi, name) << std::endl;

    std::ofstream file("Output.txt", std::ios::out);
    if (file.is_open()) {
        print(file, num, pi, name) << std::endl;
        file.close();
        std::cout << "Data written to Output.txt" << std::endl;
    } else {
        std::cerr << "Failed to open the file!" << std::endl;
    }

    std::stringstream output;
    print(output, num, pi, name) << std::endl;
    std::cout << "Output from stringstream:" << std::endl;
    std::cout << output.str();

    return 0;
}
