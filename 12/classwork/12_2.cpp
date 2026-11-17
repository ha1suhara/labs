#include <iostream>
#include <cctype>

int main(){
    int n;
    std::cout << "n = ";
    if (!(std::cin >> n) || n < 1){
        std::cout << "Wrong n\n";
        return 1;
    }
    unsigned long long *a = new unsigned long long[n];

    std::cout << "Enter " << 10 * n << " digits:\n";
    for (int i = 0; i < n; i++){
        a[i] = 0;
        for (int k = 0; k < 10; k++){
            char c;
            if (!(std::cin >> c) || !std::isdigit(static_cast<unsigned char>(c))){
                std::cout << "Expected a digit\n";
                delete[] a;
                return 1;
            }
            a[i] = a[i] * 10 + (c - '0');
        }
    }

    unsigned long long sum = 0;
    for (int i = 0; i < n; i++){
        std::cout << "a[" << i << "] = " << a[i] << '\n';
        sum += a[i];
    }
    std::cout << "Sum = " << sum << '\n';
    delete[] a;
    return 0;
}
