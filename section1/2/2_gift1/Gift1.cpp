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
    fin >> np; fin.ignore();



    for (int i = 0; i < np; ++i) {
        getline(fin, names[i]);
        accounts[names[i]] = 0;
    }



    while (fin.peek() != EOF) {
        string giver;
        int amount, numPerson, amountGiven;

        getline(fin, giver);

        fin >> amount >> numPerson; fin.ignore();

        if (numPerson == 0 || amount == 0) continue;

        amountGiven = amount / numPerson;

        for (int i = 0; i < numPerson; ++i) {
            string receiver;
            getline(fin, receiver);
            accounts[receiver] += amountGiven;
        }

        accounts[giver] -= amountGiven * numPerson;
    }

    for (int j = 0; j < np; ++j) {
        fout << names[j] << " " << accounts[names[j]] << endl;
    }

    return 0;
}