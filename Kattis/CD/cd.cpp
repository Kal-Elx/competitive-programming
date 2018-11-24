#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    unsigned jackSize, jillSize, catalogNumber, res = 0;

    cin >> jackSize >> jillSize;

    while (jackSize > 0 || jillSize > 0) {
        unordered_set<unsigned> collection;
        
        for (unsigned i = 0; i < jackSize + jillSize; ++i) {
            cin >> catalogNumber;
            collection.insert(catalogNumber);
        }
        
        res = jackSize + jillSize - collection.size();
        cin >> jackSize >> jillSize;

        cout << res << endl;
    }

    return 0;
}