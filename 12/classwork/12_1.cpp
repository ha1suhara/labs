#include <iostream>
#include <iomanip>
#include <cmath>

int main(){
    double x, y;
    std::cout << "x = ";
    std::cin >> x;
    std::cout << "y = ";
    std::cin >> y;
    if (!std::cin){
        std::cout << "Input error\n";
        return 1;
    }
    double r = std::pow(x, y);
    if (std::isnan(r)){
        std::cout << "x^y is not defined for these x and y\n";
        return 0;
    }
    std::cout << "fixed:      " << std::fixed << std::setprecision(6) << r << '\n';
    std::cout << "scientific: " << std::scientific << std::setprecision(6) << r << '\n';
    return 0;
}
