/*
PROG: gift1
ID: peiqial1
TASK: test
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");

    string names[11];
    map<string, int> accounts;

    int np;
    fin >> np;



    for (int i = 0; i < np; ++i) {
        fin >> names[i];
        accounts[names[i]] = 0;
    }



    for (int i = 0; i < np; ++i) {
        string giver;
        int amount, numPerson, amountGiven;

        fin >> giver >> amount >> numPerson; fin.ignore();

        if (numPerson == 0 || amount == 0) continue;

        amountGiven = amount / numPerson;

        for (int i = 0; i < numPerson; ++i) {
            string receiver;
            fin >> receiver;
            accounts[receiver] += amountGiven;
        }

        accounts[giver] -= amountGiven * numPerson;
    }

    for (int j = 0; j < np; ++j) {
        fout << names[j] << " " << accounts[names[j]] << endl;
    }

    return 0;
}