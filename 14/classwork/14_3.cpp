#include <iostream>
#include <fstream>
#include <string>

bool is_separator(char c){
    return c == ' ' || c == ',' || c == '.' || c == '!' || c == '?' ||
           c == '\n' || c == '\r' || c == '\t';
}

std::string reverse_utf8(const std::string &w){
    std::string r;
    size_t i = w.size();
    while (i > 0){
        size_t start = i - 1;
        while (start > 0 && (static_cast<unsigned char>(w[start]) & 0xC0) == 0x80) start--;
        r += w.substr(start, i - start);
        i = start;
    }
    return r;
}

int main(){
    std::string in_name, out_name;
    std::cout << "Encrypted file: ";
    std::cin >> in_name;
    std::cout << "Output file: ";
    std::cin >> out_name;

    std::ifstream fin(in_name);
    if (!fin){
        std::cout << "Cannot open " << in_name << '\n';
        return 1;
    }
    std::ofstream fout(out_name);
    if (!fout){
        std::cout << "Cannot create " << out_name << '\n';
        return 1;
    }

    std::string word;
    char c;
    while (fin.get(c)){
        if (is_separator(c)){
            fout << reverse_utf8(word) << c;
            word.clear();
        } else {
            word += c;
        }
    }
    fout << reverse_utf8(word);
    std::cout << "Done. Result is in " << out_name << '\n';
    return 0;
}
