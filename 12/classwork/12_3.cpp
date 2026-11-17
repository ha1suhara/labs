#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

int main(){
    int n;
    std::cout << "n = ";
    if (!(std::cin >> n) || n < 1){
        std::cout << "Wrong n\n";
        return 1;
    }
    const int W = 7;
    std::string border(W * n + 2, '+');

    std::cout << border << '\n';
    for (int i = 1; i <= n; i++)
        std::cout << std::setw(W) << i;
    std::cout << '\n' << border << '\n';

    for (int i = 1; i <= n; i++){
        double r = std::sqrt(static_cast<double>(i));
        int ri = static_cast<int>(std::lround(r));
        if (ri * ri == i)
            std::cout << std::setw(W) << ri;
        else
            std::cout << std::setw(W) << std::fixed << std::setprecision(2) << r;
    }
    std::cout << '\n' << border << '\n';
    return 0;
}
