#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>

bool create_file(const std::string &name, int n){
    std::ofstream fout(name);
    if (!fout) return false;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter " << n << " lines: surname course group grades,separated,by,commas\n";
    for (int i = 0; i < n; i++){
        std::string line;
        std::cout << i + 1 << ": ";
        std::getline(std::cin, line);
        fout << line << '\n';
    }
    return true;
}

bool parse_line(const std::string &line, std::string &surname, double &avg){
    std::istringstream in(line);
    int course;
    std::string group, rest, grades;
    if (!(in >> surname >> course >> group)) return false;
    std::getline(in, rest);
    for (size_t i = 0; i < rest.size(); i++)
        grades += (rest[i] == ',') ? ' ' : rest[i];
    std::istringstream g(grades);
    int x, cnt = 0;
    double sum = 0;
    while (g >> x){ sum += x; cnt++; }
    if (cnt == 0 || !g.eof()) return false;
    avg = sum / cnt;
    return true;
}

int main(){
    std::string name;
    int n;
    std::cout << "File name: ";
    std::cin >> name;
    std::cout << "N = ";
    if (!(std::cin >> n) || n < 1){
        std::cout << "Wrong N\n";
        return 1;
    }
    if (!create_file(name, n)){
        std::cout << "Cannot create " << name << '\n';
        return 1;
    }

    std::ifstream fin(name);
    if (!fin){
        std::cout << "Cannot open " << name << '\n';
        return 1;
    }
    std::string line, surname, worst;
    double avg, worst_avg = 0;
    int lineno = 0;
    bool found = false;
    while (std::getline(fin, line)){
        lineno++;
        if (!parse_line(line, surname, avg)){
            std::cout << "Line " << lineno << " has a wrong format and is skipped\n";
            continue;
        }
        if (!found || avg < worst_avg){
            worst_avg = avg;
            worst = surname;
            found = true;
        }
    }
    if (found)
        std::cout << "The worst average grade: " << worst << " (" << worst_avg << ")\n";
    else
        std::cout << "No correct records\n";
    return 0;
}
