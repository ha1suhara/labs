#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>

int main(){
    std::string name;
    std::cout << "File name: ";
    std::cin >> name;
    std::ifstream fin(name);
    if (!fin){
        std::cout << "Cannot open " << name << '\n';
        return 1;
    }
    std::stringstream ss;
    ss << fin.rdbuf();
    std::string text = ss.str();
    std::string low = text;
    for (size_t i = 0; i < low.size(); i++)
        low[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(low[i])));

    int line = 1, open_line = 0, errors = 0, pairs = 0;
    bool open = false;
    for (size_t i = 0; i < low.size(); i++){
        if (low[i] == '\n'){ line++; continue; }
        if (low[i] != '<') continue;

        if (low.compare(i, 3, "<td") == 0 && i + 3 < low.size() &&
            (low[i + 3] == '>' || std::isspace(static_cast<unsigned char>(low[i + 3])))){
            if (open){
                std::cout << "Line " << line << ": <td> opened, but <td> from line "
                          << open_line << " is not closed\n";
                errors++;
            }
            open = true;
            open_line = line;
            continue;
        }
        size_t j = i + 1;
        if (j < low.size() && low[j] == '/'){
            j++;
            while (j < low.size() && low[j] == ' ') j++;
            if (low.compare(j, 3, "td>") == 0){
                if (!open){
                    std::cout << "Line " << line << ": </td> without an opening <td>\n";
                    errors++;
                } else {
                    pairs++;
                }
                open = false;
            }
        }
    }
    if (open){
        std::cout << "Line " << open_line << ": <td> is never closed\n";
        errors++;
    }
    if (errors == 0)
        std::cout << "All <td> tags are correct (" << pairs << " pairs)\n";
    else
        std::cout << "Errors found: " << errors << '\n';
    return 0;
}
