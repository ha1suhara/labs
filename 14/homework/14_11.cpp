#include <iostream>
#include <fstream>
#include <string>

const int WIDTH = 50;

int text_length(const std::string &s){
    int n = 0;
    for (size_t i = 0; i < s.size(); i++)
        if ((static_cast<unsigned char>(s[i]) & 0xC0) != 0x80) n++;
    return n;
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
    int lineno = 0;
    while (std::getline(fin, line)){
        lineno++;
        if (!line.empty() && line.back() == '\r') line.pop_back();
        size_t end = line.find_last_not_of(" \t");
        if (end == std::string::npos){
            fout << '\n';
            continue;
        }
        line.erase(end + 1);
        int len = text_length(line);
        if (len % 2 == 1){
            line = " " + line;
            len++;
        }
        int pad = (WIDTH - len) / 2;
        if (pad < 0){
            pad = 0;
            std::cout << "Warning: line " << lineno << " is longer than " << WIDTH << " characters\n";
        }
        fout << std::string(pad, ' ') << line << '\n';
    }
    std::cout << "Done: " << lineno << " line(s) written to " << out_name << '\n';
    return 0;
}
