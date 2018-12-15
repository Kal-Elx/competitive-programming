#include <stdio.h>
#include <unordered_set>

using namespace std;

int main() {
    unsigned jackSize, jillSize, catalogNumber, res;

    scanf("%d",&jackSize);
    scanf("%d",&jillSize);

    while (jackSize > 0 || jillSize > 0) {
        unordered_set<unsigned> collection;
        
        for (unsigned i = 0; i < jackSize + jillSize; ++i) {
            scanf("%d",&catalogNumber);
            collection.insert(catalogNumber);
        }
        
        res = jackSize + jillSize - collection.size();
        scanf("%d",&jackSize);
        scanf("%d",&jillSize);

        printf("%d\n", res);
    }

    return 0;
}