#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>

std::string to_lower(std::string s){
    for (size_t i = 0; i < s.size(); i++)
        s[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(s[i])));
    return s;
}

bool is_article(const std::string &w){
    std::string l = to_lower(w);
    return l == "die" || l == "der" || l == "das";
}

void capitalize(std::string &w){
    if (w.empty()) return;
    unsigned char c0 = static_cast<unsigned char>(w[0]);
    if (c0 < 128){
        w[0] = static_cast<char>(std::toupper(c0));
    } else if (c0 == 0xC3 && w.size() > 1){
        unsigned char c1 = static_cast<unsigned char>(w[1]);
        if (c1 == 0xA4 || c1 == 0xB6 || c1 == 0xBC)
            w[1] = static_cast<char>(c1 - 0x20);
    }
}

int main(){
    std::string in_name, out_name;
    std::cout << "Input file: ";
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

    std::string line;
    bool prev_article = false;
    int changed = 0;
    while (std::getline(fin, line)){
        std::string result, word;
        size_t start = 0;
        while (start <= line.size()){
            size_t sp = line.find(' ', start);
            if (sp == std::string::npos) sp = line.size();
            word = line.substr(start, sp - start);
            if (prev_article && !word.empty()){
                std::string before = word;
                capitalize(word);
                if (word != before) changed++;
            }
            if (!word.empty()) prev_article = is_article(word);
            result += word;
            if (sp < line.size()) result += ' ';
            start = sp + 1;
        }
        fout << result << '\n';
    }
    std::cout << "Done. Words changed: " << changed << ". Result is in " << out_name << '\n';
    return 0;
}
