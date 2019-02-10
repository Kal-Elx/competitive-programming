#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

struct node {
    int x, y;
    bool N, E, S, W;
    bool visited;
    node* prev;
    char dir;
};

node square[7][7];

// Breadth-first search
string bfs(node* start, node* end) {
    queue<node*> q;
    q.push(start);
    start->visited = true;

    while (!q.empty()) {
        node* curr = q.front();
        q.pop();

        if (curr == end)
            break;

        if (curr->y -1 >= 1 && curr->N && !square[curr->y-1][curr->x].visited) {
            q.push(&square[curr->y-1][curr->x]);
            square[curr->y-1][curr->x].visited = true;
            square[curr->y-1][curr->x].prev = curr;
            square[curr->y-1][curr->x].dir = 'N';
        }
        if (curr->y +1 <= 6  && curr->S && !square[curr->y+1][curr->x].visited) {
            q.push(&square[curr->y+1][curr->x]);
            square[curr->y+1][curr->x].visited = true;
            square[curr->y+1][curr->x].prev = curr;
            square[curr->y+1][curr->x].dir = 'S';
        }
        if (curr->x -1 >= 1 && curr->W && !square[curr->y][curr->x -1].visited) {
            q.push(&square[curr->y][curr->x -1]);
            square[curr->y][curr->x -1].visited = true;
            square[curr->y][curr->x -1].prev = curr;
            square[curr->y][curr->x -1].dir = 'W';
        }
        if (curr->x +1 <= 6 && curr->E && !square[curr->y][curr->x +1].visited) {
            q.push(&square[curr->y][curr->x+1]);
            square[curr->y][curr->x+1].visited = true;
            square[curr->y][curr->x+1].prev = curr;
            square[curr->y][curr->x+1].dir = 'E';
        }
    }

    // Reconstruct path
    string res = "";
    node* curr = end;

    while (curr != start) {
        res += curr->dir;
        curr = curr->prev;
    }

    reverse(res.begin(), res.end());
    return res;
}

void resetSquares() {
    for (int y = 0; y < 7; ++y)
        for (int x = 0; x < 7; ++x) {
            square[y][x].x = x;
            square[y][x].y = y;
            square[y][x].N = true;
            square[y][x].E = true;
            square[y][x].S = true;
            square[y][x].W = true;
            square[y][x].visited = false;
            square[y][x].prev = nullptr;
            square[y][x].dir = '-';
        }
}

int main() {
    int startX, startY, endX, endY, x1, y1, x2, y2;
            
    while (cin >> startX >> startY) {
        if (startX == 0 && startY == 0)
            break;

        resetSquares();

        cin >> endX >> endY;
        node* start = &square[startY][startX];
        node* end = &square[endY][endX];

        // Set walls
        for (int i = 0; i < 3; ++i) {
            cin >> x1 >> y1 >> x2 >> y2;

            if (x1 == x2) { // Vertical
                for (int y = y1; y < y2; ++y) {
                    if (x1 >= 1 && y+1 <= 6)
                        square[y+1][x1].E = false;
                    if (x1+1 <= 6 && y+1 <= 6)
                        square[y+1][x1+1].W = false;
                }
            } else { // Horizontal
                for (int x = x1; x < x2; ++x) {
                    if (y1 + 1 <= 6 && x+1 <=6)
                        square[y1+1][x+1].N = false;
                    if (y1 >= 1 && x+1 <=6)
                        square[y1][x+1].S = false;
                }
            }
        }
        cout << bfs(start, end) << '\n';
    }

    return 0;
}