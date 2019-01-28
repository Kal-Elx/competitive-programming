#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct contestant {
    int contestantNumber;
    int solvedProblems = 0;
    int penaltyTime = 0;
    map<int, int> triedProblems; // <id, tried> (-1 for correct)
};

auto cmp = [](contestant const & a, contestant const & b) 
{ 
    if (a.solvedProblems != b.solvedProblems)
        return a.solvedProblems > b.solvedProblems;
    else if (a.penaltyTime != b.penaltyTime)
        return a.penaltyTime < b.penaltyTime;
    else
        return a.contestantNumber < b.contestantNumber;
};

int main() {
    int tc, cn, p, rt; // test cases, contestant number, problem, runtime
    char l; // verdict letter
    string s;

    cin >> tc;
    cin.ignore();
    cin.ignore(); // blank line

    for (int i = 0; i < tc; ++i) {
        if (i > 0)
            cout << "\n";
        
        map<int, contestant> contestants;

        while (getline(cin, s) && !s.empty()) {
            istringstream tmp(s);
            tmp >> cn >> p >> rt >> l;

            contestant& c = contestants[cn];
            c.contestantNumber = cn;

            if (c.triedProblems[p] != -1) {
                if (l == 'C') {
                    ++c.solvedProblems;
                    c.penaltyTime += 20*c.triedProblems[p] + rt;
                    c.triedProblems[p] = -1;
                } else if (l == 'I')
                    ++(c.triedProblems[p]);
            }
        }
        
        vector<contestant> scoreboard;
        for (auto const& c : contestants)
            scoreboard.push_back(c.second);

        sort(scoreboard.begin(), scoreboard.end(), cmp);
        
        for (auto const& c : scoreboard)
            cout << c.contestantNumber << ' ' << c.solvedProblems << ' ' << c.penaltyTime << '\n';
    }
    return 0;
}
