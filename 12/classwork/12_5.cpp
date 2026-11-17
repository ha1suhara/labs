#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>

int main(){
    std::string name;
    std::cout << "Input file (e.g. input.txt): ";
    std::cin >> name;
    std::ifstream fin(name);
    if (!fin){
        std::cout << "Cannot open " << name << '\n';
        return 1;
    }

    int cap = 1024, n = 0;
    unsigned long long *a = new unsigned long long[cap];
    unsigned long long v;
    while (fin >> v){
        if (n == cap){
            unsigned long long *b = new unsigned long long[cap * 2];
            for (int i = 0; i < n; i++) b[i] = a[i];
            delete[] a;
            a = b;
            cap *= 2;
        }
        a[n++] = v;
    }

    std::cout << std::fixed << std::setprecision(3);
    for (int i = n - 1; i >= 0; i--)
        std::cout << std::sqrt(static_cast<long double>(a[i])) << '\n';

    delete[] a;
    return 0;
}
