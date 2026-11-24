#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define LEN 256

int main() {
    char line[LEN];
    char words[MAX_WORDS][LEN]; // тут зберігаю різні слова
    int count = 0;
    int n;

    fgets(line, LEN, stdin);
    sscanf(line, "%d", &n);

    for (int i = 0; i < n; i++) {
        if (fgets(line, LEN, stdin) == NULL)
            break;

        // все в нижній регістр, щоб Hello і hello було одне слово
        for (int j = 0; j < (int)strlen(line); j++)
            line[j] = tolower((unsigned char)line[j]);

        char *w = strtok(line, " \t\n.,;:!?\"()-");
        while (w != NULL) {
            // перевіряю чи таке слово вже було
            int found = 0;
            for (int k = 0; k < count; k++) {
                if (strcmp(words[k], w) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found && count < MAX_WORDS) {
                strcpy(words[count], w);
                count++;
            }
            w = strtok(NULL, " \t\n.,;:!?\"()-");
        }
    }

    printf("%d\n", count);
    return 0;
}
