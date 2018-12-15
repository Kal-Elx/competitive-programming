#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<string> divide(const string& tour) {
    vector<string> res;
    string subtour;
    int depth = 0;

    for (char direction : tour.substr(1, tour.length()-2)) {
        subtour += direction;
        if (direction == '0')
            ++depth;
        else
            --depth;
        if (depth == 0) {
            res.push_back(subtour);
            subtour.clear();
        }
    }

    return res;
}

bool compare(const string& tour1, const string& tour2) {
    if (tour1 == tour2)
        return true;
    
    if (tour1.size() == tour2.size()) {
        vector<string> subtours1 = divide(tour1), subtours2 = divide(tour2);
        set<int> skip;
        if (subtours1.size() == subtours2.size()) {
            for (int i = 0; i < subtours1.size(); ++i) {
                bool foundMatch = false;       
                for (int j = 0; j < subtours2.size(); ++j)
                    if (skip.find(j) == skip.end() && compare(subtours1[i], subtours2[j])) {
                        skip.insert(j);
                        foundMatch = true;
                        break;
                    }
                if (!foundMatch)
                    return false;
            }
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    string tour1, tour2;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> tour1 >> tour2;
        
        if (compare('0' + tour1 + '1', '0' + tour2 + '1'))
            cout << "same\n";
        else
            cout << "different\n";
    }

    return 0;
}