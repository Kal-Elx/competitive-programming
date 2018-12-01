#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int finalPos[5][5] = {{1, 1, 1, 1, 1},
                            {0, 1, 1, 1, 1},
                            {0, 0, 2, 1, 1},
                            {0, 0, 0, 0, 1},
                            {0, 0, 0, 0, 0}};
const pair<int, int> moves[8] = {make_pair(-2, -1), make_pair(-1, -2),
                                 make_pair(-2, 1), make_pair(1, -2),
                                 make_pair(2, -1), make_pair(-1, 2),
                                 make_pair(2, 1), make_pair(1, 2)};

bool isCorrect(int board[5][5]) {
    if (board[2][2] != 2)
        return false;
    for (int r = 0; r < 5; ++r) {
        for (int c = 0; c < 5; ++c) {
            if (board[r][c] != finalPos[r][c])
                return false;
        }
    }
    return true;
}

bool inBounds(int r, int c) {
    return r >= 0 && r < 5 && c >= 0 && c < 5;
}

bool isMoveBack(pair<int, int> open, pair<int, int> move, pair<int, int> lastPos) {
    return open.first + move.first == lastPos.first && open.second + move.second == lastPos.second;
}

int calcMoves(int board[5][5], pair<int, int> open, pair<int, int> lastPos = make_pair(-1, -1), int depth = -1) {
    ++depth;
    int r, c, champ = 11;
    if (depth > 10 || isCorrect(board))
        return depth;
    for (pair<int, int> move : moves) {
        if (inBounds(open.first + move.first, open.second + move.second) && !isMoveBack(open, move, lastPos)) {
            swap(board[open.first][open.second], board[open.first + move.first][open.second + move.second]); // make move
            champ = min(calcMoves(board, make_pair(open.first + move.first, open.second + move.second), open, depth), champ);
            swap(board[open.first + move.first][open.second + move.second], board[open.first][open.second]); // move back
        }
    }
    return champ;
}

int main() {
    int n, board[5][5];
    pair<int, int> open;
    string row;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        for (int r = 0; r < 5; ++r) {
            getline(cin, row);
            for (int c = 0; c < 5; ++c) {
                switch (row[c]) {
                    case '0':
                        board[r][c] = 0;
                        break;
                    case '1':
                        board[r][c] = 1;
                        break;
                    case ' ':
                        board[r][c] = 2;
                        open = make_pair(r, c);
                        break;
                }
            }
        }
        int moves = calcMoves(board, open);
        if (moves < 11)
            cout << "Solvable in " << moves << " move(s)." << endl;
        else
            cout << "Unsolvable in less than 11 move(s)." << endl;
    }

    return 0;
}