#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<string, string> dictionary;
    string input, englishWord, foreignWord;

    while (getline(cin, input)) {
        if (input == "") {
            break;
        }

        size_t x = input.find(" ");
        englishWord = input.substr(0, x);
        foreignWord = input.substr(x+1, input.length()-1); 
        
        dictionary[foreignWord] = englishWord;
    }

    while (cin >> foreignWord) {
        cout << (dictionary.find(foreignWord) != dictionary.cend() ? dictionary[foreignWord] : "eh") << endl;
    }

    return 0;
}
