#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

const int W = 9;
const int PER_ROW = 8;

void print_block(int from, int to){
    std::string border(W * (to - from + 1), '+');
    std::cout << border << '\n';
    for (int i = from; i <= to; i++)
        std::cout << std::left << std::setw(W) << i;
    std::cout << '\n' << border << '\n';
    for (int i = from; i <= to; i++){
        double r = std::sqrt(static_cast<double>(i));
        long long ri = std::llround(r);
        if (ri * ri == i)
            std::cout << std::left << std::setw(W) << ri;
        else
            std::cout << std::left << std::setw(W) << std::fixed << std::setprecision(2) << r;
    }
    std::cout << '\n' << border << "\n\n";
}

int main(){
    int n;
    std::cout << "n = ";
    if (!(std::cin >> n) || n < 1){
        std::cout << "Wrong n\n";
        return 1;
    }
    for (int from = 1; from <= n; from += PER_ROW){
        int to = from + PER_ROW - 1;
        if (to > n) to = n;
        print_block(from, to);
    }
    return 0;
}
