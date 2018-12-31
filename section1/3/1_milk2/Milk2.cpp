/*
PROG: milk2
ID: peiqial1
TASK: test
LANG: C++
*/

#include <fstream>

using namespace std;

short farmerChange[1000000] = {0};

int main() {

    ofstream fout("milk2.out");
    ifstream fin("milk2.in");

    int n;
    fin >> n;

    int beginTime = 1000000, endTime = 0;

    for (int i = 0; i < n; ++i) {
        int start, finish;
        fin >> start >> finish;
        farmerChange[start]++;
        farmerChange[finish]--;
        if (start < beginTime) beginTime = start;
        if (finish > endTime) endTime = finish;
    }

    bool initFlag = true;
    int longestIdle = 0, currentIdle = 0, longestNonIdle = 0, currentNonIdle = 0;
    short currentFarmerNumber = 0;
    for (int j = beginTime; j <= endTime; ++j) {
        if (currentIdle > longestIdle) longestIdle = currentIdle;
        if (currentNonIdle > longestNonIdle) longestNonIdle = currentNonIdle;

        if (farmerChange[j] != 0) {
            currentFarmerNumber += farmerChange[j];

//            cout << "@" << j << ", Farmer is now " << currentFarmerNumber << endl;

            if (currentFarmerNumber == 0) {
                currentNonIdle = 0;
            } else {
                currentIdle = 0;
            }
            initFlag = false;
        }

        if (currentFarmerNumber == 0 && !initFlag) currentIdle++;
        if (currentFarmerNumber > 0) currentNonIdle++;
    }

    fout << longestNonIdle << " " << longestIdle << endl;

    return 0;
}
