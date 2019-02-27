#include <iostream>
#include <string>
#include <queue>
#include <tuple>
#include <set>

using namespace std;

struct square {
    bool nwse[4] = {0, 0, 0, 0};

    void set(const string& d) {
        for (int i = 0; i < d.length(); ++i) {
            switch (d[i]) {
                case 'N':
                    nwse[0] = 1;
                    break;
                case 'W':
                    nwse[1] = 1;
                    break;
                case 'S':
                    nwse[2] = 1;
                    break;
                case 'E':
                    nwse[3] = 1;
                    break;
            }
        }
    }

    bool n(int time) {
        return nwse[time%4];
    }
    bool w(int time) {
        return nwse[(1+time)%4];
    }
    bool s(int time) {
        return nwse[(2+time)%4];
    }
    bool e(int time) {
        return nwse[(3+time)%4];
    }
};

struct step {
    int r, c, time;

    step(int a, int b, int t) {
        r = a;
        c = b;
        time = t;
    }
};

int main() {
    int R, C;
    string d;
    while (cin >> R >> C) {
        square maze[R][C];
        cin.ignore();
        for (int r = 0; r < R; ++r)
            for (int c = 0; c < C && (c < C-1 || r < R-1); ++c) {
                getline(cin, d);
                maze[r][c].set(d);
            }

        queue<step> q;
        set<tuple<int, int, int>> processed; 
        step start(0, 0, 0);
        q.push(start);
        bool path = false;

        while (!q.empty()) {
            step st = q.front();
            int r = st.r; 
            int c = st.c;
            int t = st.time;
            q.pop();

            if (r == R-1 && c == C-1) {
                cout << t << '\n';
                path = true;
                break;
            }

            tuple<int, int, int> curr(r,c,t%4);
            if (processed.find(curr) != processed.end())
                continue;
            else
                processed.insert(curr);

            square sq = maze[r][c];

            if (sq.n(t) && r > 0) {
                step next(r-1, c, t+1);
                q.push(next);
            }
            if (sq.s(t) && r < R-1) {
                step next(r+1, c, t+1);
                q.push(next);
            }
            if (sq.w(t) && c > 0) {
                step next(r, c-1, t+1);
                q.push(next);
            }
            if (sq.e(t) && c < C-1) {
                step next(r, c+1, t+1);
                q.push(next);
            }
        }
        if (!path)
            cout << "no path to exit\n";
    }
    return 0;
}