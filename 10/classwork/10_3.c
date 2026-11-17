#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
    int day, month, year;
} Date;

int is_leap(int y){
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

int days_in_month(int m, int y){
    static const int d[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (m == 2 && is_leap(y)) ? 29 : d[m - 1];
}

int is_valid(Date d){
    return d.year >= 1 && d.month >= 1 && d.month <= 12 &&
           d.day >= 1 && d.day <= days_in_month(d.month, d.year);
}

Date tomorrow(Date d){
    d.day++;
    if (d.day > days_in_month(d.month, d.year)){
        d.day = 1;
        d.month++;
        if (d.month > 12){
            d.month = 1;
            d.year++;
        }
    }
    return d;
}

int day_of_week(Date d){
    static const int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    int y = d.year;
    if (d.month < 3) y--;
    return (y + y / 4 - y / 100 + y / 400 + t[d.month - 1] + d.day) % 7;
}

int main(){
    const char *names[] = { "Sunday", "Monday", "Tuesday", "Wednesday",
                            "Thursday", "Friday", "Saturday" };
    Date d, t;
    printf("Date (dd.mm.yyyy): ");
    if (scanf("%d.%d.%d", &d.day, &d.month, &d.year) != 3 || !is_valid(d)){
        printf("Wrong date\n");
        return 0;
    }
    t = tomorrow(d);
    printf("Tomorrow: %02d.%02d.%04d\n", t.day, t.month, t.year);
    printf("Day of week: %s\n", names[day_of_week(d)]);
    return 0;
}
