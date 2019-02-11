#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
    int n, largest, res = 0;
    vector<int> input;

    while (cin >> n) { 
        if (n == 0)
            break;
        input.push_back(n);
    }
        
    largest = *(max_element(input.begin(), input.end()));
    vector<int> table;

    for (int i = 1; i <= largest; ++i) {
        res += pow(i, 2);
        table.push_back(res);
    }

    for (int m : input)
        cout << table[m-1] << '\n';

    return 0;
}