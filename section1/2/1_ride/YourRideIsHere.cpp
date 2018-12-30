/*
PROG: ride
ID: peiqial1
TASK: test
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a(8,'\0'), b(8,'\0');
    getline(fin, a);
    getline(fin, b);

    int i, aReduce = 1, bReduce = 1;

    for (i = 0; i < a.length(); i++) {
        aReduce = aReduce * (a[i] - 'A' + 1) % 47;
    }

    for (i = 0; i < b.length(); i++) {
        bReduce = bReduce * (b[i] - 'A' + 1) % 47;
    }

    if (aReduce == bReduce) {
        fout << "GO" << endl;
    } else {
        fout << "STAY" << endl;
    }

    return 0;
}