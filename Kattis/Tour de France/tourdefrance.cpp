#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int f, r;

    while (cin >> f) {
        if (f == 0) {
            break;
        }
        cin >> r;

        vector<int> frontSprockets(f), rearSprockets(r);

        int teeth;
        for (int i = 0; i < f; ++i) {
            cin >> teeth;
            frontSprockets[i] = teeth;
        }
        for (int i = 0; i < r; ++i) {
            cin >> teeth;
            rearSprockets[i] = teeth;
        }

        vector<double> driveRatios;
        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < r; ++j) {
                driveRatios.push_back((double)rearSprockets[j] / frontSprockets[i]);
            }            
        }

        sort(driveRatios.begin(), driveRatios.end());
        
        double champion = 0;
        for (auto it = driveRatios.begin() + 1; it != driveRatios.end(); ++it) {
            champion = max(champion, (*it / *prev(it)));
        }

        cout << setprecision (2) << fixed << champion << endl;
    }

    return 0;
}