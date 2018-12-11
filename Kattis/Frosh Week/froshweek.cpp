/*
 * Inspiration from
 * https://www.ida.liu.se/opendsa/OpenDSA/Books/TDDD86F18/html/MergesortImpl.html
 */

#include <stdio.h>

unsigned long long swaps;
unsigned array[1000000], temp[1000000];

void mergeSort(unsigned left, unsigned right) {
    if (left == right) return;
    
    unsigned mid = (left + right)/2;
    mergeSort(left, mid);
    mergeSort(mid+1, right);
    
    for (unsigned i = left; i <= right; ++i)
        temp[i] = array[i];
    
    unsigned i1 = left, i2 = mid+1, steps = i2-i1;

    for (unsigned curr = left; curr <= right; ++curr) {
        if (i1 == mid+1)
            array[curr] = temp[i2++];
        else if (i2 > right)
            array[curr] = temp[i1++];
        else if (temp[i1] <= temp[i2]) {
            array[curr] = temp[i1++];
            --steps;
        } else {
            array[curr] = temp[i2++];
            swaps += steps;
        }
    }    
}

int main() {
    unsigned n;

    while (scanf("%d",&n)!=EOF) {
        swaps = 0;

        for (int i = 0; i < n; ++i) {
            scanf("%d", &array[i]);
        }

        mergeSort(0, n-1);
        printf("%lld\n", swaps);
    }

    return 0;
}