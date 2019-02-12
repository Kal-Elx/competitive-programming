#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string input, res;
    vector<string> longIntegers;
    int mostDigits = 0;

    while (cin >> input) {
        if (input == "0")
            break;
        
        reverse(input.begin(), input.end());
        longIntegers.push_back(input);
        mostDigits = input.length() > mostDigits ? input.length() : mostDigits;
    }

    int overflow = 0;
    for (int i = 0; i < mostDigits; ++i) {
        int sum = 0;
        for (string longInt : longIntegers)
            if (longInt.length() > i )
                sum += (longInt[i] - '0'); // char to int

        sum += overflow % 10;
        overflow = overflow / 10 + sum / 10;
        res.append((to_string(sum % 10)));
    }

    while (overflow != 0) {
        res.append(to_string(overflow%10));
        overflow /= 10;
    } 

    reverse(res.begin(), res.end());
    cout << res << endl;
    return 0;
}