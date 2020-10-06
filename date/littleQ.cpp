#include <iostream>

using namespace std;

//
// Created by 陈姝宇 on 2020/9/15.
//
class LittleQ {
    int isLeapYear(int year) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            return 1;
        } else return 0;
    }

    int main() {
        int n;
        cin >> n;
        int days;
        int now_year = 2013;
        int now_month = 3;
        int now_day = 24;

        int month_day[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, // 0
                                {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}}; // 1

        while (n--) {
            cin >> days;
            int year0, month0, day0;
            year0 = now_year;
            month0 = now_month;
            day0 = now_day;
            int year1, month1, day1;
            int year2, month2, day2;
            year1 = year2 = year0;
            month1 = month2 = month0;
            day1 = day2 = day0;

            // to future
            int forward = days;
            if (forward + day1 > month_day[isLeapYear(year1)][month1]) {
                forward = forward + day1 - month_day[isLeapYear(year1)][month1];
                ++month1;
                if (month1 > 12) {
                    month1 = 1;
                    ++year1;
                }
                while (forward > month_day[isLeapYear(year1)][month1]) {
                    forward -= month_day[isLeapYear(year1)][month1];
                    // next month
                    ++month1;
                    if (month1 > 12) { // may update year
                        month1 = 1;
                        ++year1;
                    }
                }
                day1 = forward;
            } else {
                day1 += forward;
            }

            // to pass
            int pass = days;
            if (day2 >= pass) {
                day2 -= pass;
            } else {
                pass -= day2;
                --month2;
                if (month2 < 1) {
                    month2 = 12;
                    --year2;
                }
                while (pass >= month_day[isLeapYear(year2)][month2]) {
                    pass -= month_day[isLeapYear(year2)][month2];
                    --month2;
                    if (month2 < 1) {
                        month2 = 12;
                        --year2;
                    }
                }
                day2 = month_day[isLeapYear(year2)][month2] - pass;
            }

            printf("%04d/%02d/%02d %04d/%02d/%02d\n", year1, month1, day1, year2, month2, day2);
        }
        return 0;
    }
};