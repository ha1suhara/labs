#include <iostream>
#include <fstream>
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
    int *m = new int[n];
    double *x = new double[n];

    std::cout << "Enter " << n << " integers m_i: ";
    for (int i = 0; i < n; i++)
        if (!(std::cin >> m[i])){
            std::cout << "Input error\n";
            delete[] m; delete[] x;
            return 1;
        }

    std::string in_name, out_name;
    std::cout << "Input file with x_i: ";
    std::cin >> in_name;
    std::ifstream fin(in_name);
    if (!fin){
        std::cout << "File " << in_name << " does not exist or cannot be opened\n";
        delete[] m; delete[] x;
        return 1;
    }
    for (int i = 0; i < n; i++)
        if (!(fin >> x[i])){
            std::cout << "File is incorrect: expected " << n << " real numbers, "
                      << "error at number " << i + 1 << '\n';
            delete[] m; delete[] x;
            return 1;
        }
    std::string rest;
    if (fin >> rest)
        std::cout << "Warning: the file contains extra data after " << n << " numbers\n";
    fin.close();

    std::cout << "Output file: ";
    std::cin >> out_name;
    std::ofstream fout(out_name);
    if (!fout){
        std::cout << "Cannot create " << out_name << '\n';
        delete[] m; delete[] x;
        return 1;
    }
    for (int i = 0; i < n; i++){
        double r = std::pow(x[i], m[i]);
        if (std::isnan(r) || std::isinf(r))
            fout << "undefined\n";
        else
            fout << std::setprecision(10) << r << '\n';
    }
    std::cout << "Done, results are in " << out_name << '\n';
    delete[] m;
    delete[] x;
    return 0;
}
