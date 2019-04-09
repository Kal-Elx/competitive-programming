#include <stdio.h>
#include <vector>

#define piece pair<pair<int, int>, char>

using namespace std;

bool board[8][8];

bool inBoard(int r, int c) {
    return r >= 0 && r < 8 && c >= 0 && c < 8;
}

bool pawn(pair<int, int> pos, pair<int, int> kingpos, bool white) {
    int dir = white ? -1 : 1;
    if (inBoard(pos.first + dir, pos.second + 1) && pos.first + dir == kingpos.first && pos.second + 1 == kingpos.second)
        return true;
    else if (inBoard(pos.first + dir, pos.second - 1) && pos.first + dir == kingpos.first && pos.second - 1 == kingpos.second)
        return true;
    return false;
}

bool rook(pair<int, int> pos, pair<int, int> kingpos) {
    int r = pos.first, c = pos.second;
    while (inBoard(++r,c)) {
        if (r == kingpos.first && c == kingpos.second)
            return true;
        else if (board[r][c])
            break;
    }
    r = pos.first, c = pos.second;
    while (inBoard(--r,c)) {
        if (r == kingpos.first && c == kingpos.second)
            return true;
        else if (board[r][c])
            break;
    }
    r = pos.first, c = pos.second;
    while (inBoard(r,++c)) {
        if (r == kingpos.first && c == kingpos.second)
            return true;
        else if (board[r][c])
            break;
    }
    r = pos.first, c = pos.second;
    while (inBoard(r,--c)) {
        if (r == kingpos.first && c == kingpos.second)
            return true;
        else if (board[r][c])
            break;
    }
    return false;
}

bool bishop (pair<int, int> pos, pair<int, int> kingpos) {
    int r = pos.first, c = pos.second;
    while (inBoard(++r,++c)) {
        if (r == kingpos.first && c == kingpos.second)
            return true;
        else if (board[r][c])
            break;
    }
    r = pos.first, c = pos.second;
    while (inBoard(--r,++c)) {
        if (r == kingpos.first && c == kingpos.second)
            return true;
        else if (board[r][c])
            break;
    }
    r = pos.first, c = pos.second;
    while (inBoard(++r,--c)) {
        if (r == kingpos.first && c == kingpos.second)
            return true;
        else if (board[r][c])
            break;
    }
    r = pos.first, c = pos.second;
    while (inBoard(--r,--c)) {
        if (r == kingpos.first && c == kingpos.second)
            return true;
        else if (board[r][c])
            break;
    }
    return false;
}

bool knight(pair<int, int> pos, pair<int, int> kingpos) {
    const pair<int, int> moves[8] = {make_pair(-2, -1), make_pair(-1, -2),
                                 make_pair(-2, 1), make_pair(1, -2),
                                 make_pair(2, -1), make_pair(-1, 2),
                                 make_pair(2, 1), make_pair(1, 2)};
    
    for (pair<int, int> move : moves) {
        int r = pos.first + move.first, c = pos.second + move.second;
        if (inBoard(r, c) && kingpos.first == r && kingpos.second == c)
            return true;
    }
    return false;
}

bool check(piece p, pair<int, int> kingpos) {
    switch (p.second) {
        case 'p':
            return pawn(p.first, kingpos, false);
        case 'P':
            return pawn(p.first, kingpos, true);
        case 'r':
        case 'R':
            return rook(p.first, kingpos);
        case 'b':
        case 'B':
            return bishop(p.first, kingpos);
        case 'q':
        case 'Q':
            return rook(p.first, kingpos) || bishop(p.first, kingpos);
        case 'n':
        case 'N':
            return knight(p.first, kingpos);
    }
    return false;
}

int main() {
    char in;
    int g = 0;

    while (true) {
        vector<piece> white;
        vector<piece> black;
        pair<int, int> whiteKing = make_pair(-1,-1);
        pair<int, int> blackKing = make_pair(-1,-1);
        bool whiteChecked = false;
        bool blackChecked =  false;
        
        for (int r = 0; r < 8; ++r) {
              for (int c = 0; c < 8; ++c) {
                scanf(" %c", &in);
                if (in >= 65 && in <= 90) {
                    white.push_back(make_pair(make_pair(r,c), in));
                    board[r][c] = true;
                } else if (in >= 97 && in <= 122) {
                    black.push_back(make_pair(make_pair(r,c), in));
                    board[r][c] = true;
                } else {
                    board[r][c] = false;
                }
                if (in == 'K')
                    whiteKing = make_pair(r,c);
                else if (in == 'k')
                    blackKing = make_pair(r,c);
            }
        }
        if (whiteKing.first == -1)
            break;

        for (piece p : white) {
            if (check(p, blackKing)) {
                blackChecked = true;
                break;
            }
        }
        if (!blackChecked)
            for (piece p : black) {
                if (check(p, whiteKing)) {
                whiteChecked = true;
                break;
            }
        }

        ++g;
        if (whiteChecked)
            printf("Game #%d: white king is in check.\n", g);
        else if (blackChecked)
            printf("Game #%d: black king is in check.\n", g);
        else
            printf("Game #%d: no king is in check.\n", g);
        }
    return 0;
}