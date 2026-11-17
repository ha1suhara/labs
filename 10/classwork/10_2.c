#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char file;
    int rank;
} ChessField;

bool input_field(ChessField *f){
    if (scanf(" %c%d", &f->file, &f->rank) != 2) return false;
    if (f->file >= 'A' && f->file <= 'H') f->file = (char)(f->file - 'A' + 'a');
    return f->file >= 'a' && f->file <= 'h' && f->rank >= 1 && f->rank <= 8;
}

bool queen_can_move(ChessField from, ChessField to){
    int dx = abs(from.file - to.file);
    int dy = abs(from.rank - to.rank);
    if (dx == 0 && dy == 0) return false;
    return dx == 0 || dy == 0 || dx == dy;
}

int main(){
    ChessField a, b;
    printf("From (e.g. d1): ");
    if (!input_field(&a)){ printf("Wrong field\n"); return 0; }
    printf("To (e.g. h5): ");
    if (!input_field(&b)){ printf("Wrong field\n"); return 0; }
    printf(queen_can_move(a, b) ? "Yes, the queen can move\n" : "No, the queen cannot move\n");
    return 0;
}
