#include <cstdio>
#include <cstring>
#include <cctype>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// спочатку більша частота, при рівній — за алфавітом
bool compareWords(const pair<string, size_t> &a, const pair<string, size_t> &b) {
    if (a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}

int main() {
    char line[256];
    int n;

    if (fgets(line, sizeof(line), stdin) == NULL || sscanf(line, "%d", &n) != 1 || n < 0) {
        printf("ERROR\n");
        return 0;
    }

    map<string, size_t> freq;

    for (int i = 0; i < n; i++) {
        if (fgets(line, sizeof(line), stdin) == NULL) {
            printf("ERROR\n");          // рядків менше, ніж n
            return 0;
        }
        // якщо '\n' не вмістився в буфер і файл ще не закінчився — рядок задовгий
        if (strchr(line, '\n') == NULL && !feof(stdin)) {
            printf("ERROR\n");
            return 0;
        }

        // не-літери замінюємо пробілами, літери переводимо в нижній регістр
        int len = strlen(line);
        for (int j = 0; j < len; j++) {
            unsigned char c = line[j];
            if (c < 128 && isalpha(c))
                line[j] = tolower(c);
            else
                line[j] = ' ';
        }

        // ділимо рядок на слова
        char *word = strtok(line, " ");
        while (word != NULL) {
            freq[word]++;
            word = strtok(NULL, " ");
        }
    }

    vector<pair<string, size_t> > words(freq.begin(), freq.end());
    sort(words.begin(), words.end(), compareWords);

    printf("%d\n", (int)words.size());
    for (size_t i = 0; i < words.size(); i++)
        printf("%s %d\n", words[i].first.c_str(), (int)words[i].second);

    return 0;
}
