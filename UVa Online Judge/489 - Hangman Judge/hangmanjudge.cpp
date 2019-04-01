#include <iostream>
#include <string>

using namespace std;

bool triedLetter[26];
const int ASCII_OFFSET = 97;
const int GUESS_LIMIT = 7;

int correctLetters(const string& solution, char guess) {
    int res = 0;
    for (char c : solution)
        res += (guess == c);
    return res;
}

int main() {
    int currRound, correct, wrong;
    bool chickenedOut;
    string solution, guess;

    while (cin >> currRound >> solution) {
        if (currRound == -1)
            break;

        cout << "Round " << currRound << '\n';
        for (int i = 0; i < 26; ++i)
            triedLetter[i] = false;
        correct = 0;
        wrong = 0;
        chickenedOut = true;
        cin >> guess;

        for (char g : guess) {
            if (!triedLetter[g-ASCII_OFFSET]) {
                triedLetter[g-ASCII_OFFSET] = true;
                int currGuess = correctLetters(solution, g);
                correct += currGuess;
                if (currGuess == 0)
                    ++wrong;
                else if(correct == solution.length()) {
                    cout << "You win.\n";
                    chickenedOut = false;
                    break;
                }
            }
            if (wrong >= GUESS_LIMIT) {
                cout << "You lose.\n";
                chickenedOut = false;
                break;
            }
        }
        if (chickenedOut)
            cout << "You chickened out.\n";
    }
    return 0;
}