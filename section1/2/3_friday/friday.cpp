/*
PROG: friday
ID: peiqial1
TASK: test
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout("friday.out");
    ifstream fin("friday.in");

    int n;
    fin >> n;
    n += 1900;

    //0 = sat, 1 = sun, 2 = mon... 6 = fri
    int daysCount[7] = {0};

    //1900.1.13 is Sat
    int dayCounter = 0;

    for (int year = 1900; year < n; ++year) {
        bool isLeapYear = (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));

        for (int month = 1; month <= 12; ++month) {
            daysCount[dayCounter] += 1;
//            cout << year << "." << month << "." << "13 is " << dayCounter << endl;
//            cout << dayCounter << " now has " << daysCount[dayCounter] << endl;

            if (month == 2) {
                dayCounter += 28;
                if (isLeapYear) {
                    dayCounter += 1;
//                    cout << year << " is leap year" << endl;
                }
            } else {
                dayCounter += 30;

                if ((month <= 7 && month % 2 == 1) || (month > 7 && month % 2 == 0)) {
//                    cout << year << "." << month << " has 31 days" << endl;
                    dayCounter += 1;
                }
            }

            dayCounter %= 7;
        }
    }

    for (int i = 0; i < 6; ++i) {
        fout << daysCount[i] << " ";
    }
    fout << daysCount[6] << endl;

    return 0;
}