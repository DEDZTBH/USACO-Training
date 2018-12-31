/*
PROG: beads
ID: peiqial1
TASK: test
LANG: C++
*/

#include <fstream>
#include <vector>

using namespace std;

struct BeadsGroup {
    char color;
    int number;
};

vector<BeadsGroup> beadsGroups = vector<BeadsGroup>();

int addValidBeads(int index, char* color) {
    struct BeadsGroup selectedGroup = beadsGroups[index];
    if (selectedGroup.color == *color || selectedGroup.color == 'w' || *color == 'w') {
        if (*color == 'w' && selectedGroup.color != 'w') {
            *color = selectedGroup.color;
        }
        return selectedGroup.number;
    } else {
        return -1;
    }
}

int main() {
    ofstream fout("beads.out");
    ifstream fin("beads.in");

    int n;
    fin >> n;

    for (int i = 0; i < n; ++i) {
        char bead;
        fin >> bead;

        if (beadsGroups.empty() || beadsGroups[beadsGroups.size() - 1].color != bead) {
            //start a new group
            struct BeadsGroup newGroup = {bead, 1};
            beadsGroups.emplace_back(newGroup);
        } else {
            beadsGroups[beadsGroups.size() - 1].number++;
        }
    }

//    for (auto &beadsGroup : beadsGroups) {
//        cout << beadsGroup.color << ":" << beadsGroup.number << " ";
//    }
//    cout << endl;

    int size = static_cast<int>(beadsGroups.size()), maxCount = 0;
    bool allBeadsSameColorFlag = false;

    for (int i = 0; i < size; ++i) {
        char forwardColor = 'w', backwardColor = 'w';
        int forwardIndex = i, backwardIndex = i, loopMaxCount = 0;

        //scan forward, not looking at current indexed one
        for (;;) {
            if (--forwardIndex < 0) {
                forwardIndex = size - 1;
            }

            int increment = addValidBeads(forwardIndex, &forwardColor);

            if (increment < 0) {
                forwardIndex++;
                break;
            } else {
                loopMaxCount += increment;
            }

            if (forwardIndex == i) {
                //All beads are same color
                allBeadsSameColorFlag = true;
                break;
            }
        }

        //All beads are same color
        if (allBeadsSameColorFlag) {
            maxCount = n;
            break;
        }

//        int temp = loopMaxCount;

        //scan backward, looking at current indexed one
        for (;;) {

            int increment = addValidBeads(backwardIndex, &backwardColor);

            if (increment < 0) {
                break;
            } else {
                loopMaxCount += increment;
            }

            if (++backwardIndex >= size) {
                backwardIndex = 0;
            }

            if (backwardIndex == forwardIndex) {
                //beads already used
                break;
            }
        }

//        cout << "when i is " << i << " Loop Max is " << loopMaxCount << " = " << temp << " + "<< loopMaxCount - temp << endl;
        if (loopMaxCount > maxCount) {
            maxCount = loopMaxCount;
        }
    }

    fout << maxCount << endl;

    return 0;
}