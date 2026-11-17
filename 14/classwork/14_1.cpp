#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::string name;
    std::cout << "File name: ";
    std::cin >> name;
    std::ifstream fin(name);
    if (!fin){
        std::cout << "Cannot open " << name << '\n';
        return 1;
    }

    double result, d;
    char op;
    int count = 1;
    if (!(fin >> result)){
        std::cout << "Wrong format: the expression must start with a number\n";
        return 1;
    }
    while (true){
        if (!(fin >> op)){
            std::cout << "Wrong format: the '=' sign is missing\n";
            return 1;
        }
        if (op == '=') break;
        if (op != '+' && op != '-'){
            std::cout << "Wrong format: unexpected symbol '" << op << "'\n";
            return 1;
        }
        if (!(fin >> d)){
            std::cout << "Wrong format: a number is expected after '" << op << "'\n";
            return 1;
        }
        result = (op == '+') ? result + d : result - d;
        count++;
    }
    if (count < 2) std::cout << "Note: the expression contains only one number\n";
    std::cout << "Result = " << result << '\n';
    return 0;
}
