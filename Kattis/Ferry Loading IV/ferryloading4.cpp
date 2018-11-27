#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    int c, l, m, count, carLength;
    string side;

    cin >> c;

    for (int i = 0; i < c; ++i) {
        queue<int> left, right;
        count = 0;

        cin >> l >> m;
        l *= 100; // Convert to centimeters;
        
        for (int j = 0; j < m; ++j) {
            cin >> carLength >> side;

            if (side == "left")
                left.push(carLength);
            else
                right.push(carLength);
        }

        queue<int>* current = &right;
        while (!(left.empty() && right.empty())) {
            current = (*current == left ? &right : &left); // Switch side
            int totalLength = 0;
            while (!current->empty() && current->front() + totalLength <= l) {
                totalLength += current->front();
                current->pop();
            }
            ++count;
        }
        cout << count << endl;
    }

    return 0;
}