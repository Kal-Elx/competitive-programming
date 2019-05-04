#include <iostream>
#include <string>

using namespace std;

struct elem {
    elem *next = nullptr;
    char val;
};

int main() {
    string in;
    while(cin >> in){
        elem *begin = new elem();
        elem *end = begin;
        elem *curr = begin;
        for (char c : in) {
            switch (c) {
                case '[':
                    curr = begin;
                    break;
                case ']':
                    curr = end;
                    break;
                default:
                    elem *newElem = new elem();
                    newElem->next = curr->next;
                    newElem->val = c;
                    if (curr == end)
                        end = newElem;
                    curr->next = newElem;
                    curr = newElem;
                    break;
            }
        }
        curr = begin->next;
        delete begin;
        while(curr != nullptr) {
            cout << curr->val;
            elem *trash = curr;
            curr = curr->next;
            delete trash;
        }
        cout << '\n';   
    }
    return 0;
}