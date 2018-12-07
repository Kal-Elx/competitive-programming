#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct Person {
    string birth;
    string death;
    set<string> parents;
    set<string> children;
};

map<string, Person> people;

vector<pair<int, int>> parse(const string& input) {
    vector<pair<int, int>> res;
    int curr = 1;
    int i = 1;
    for (i; i < input.length(); ++i) {
        if (input[i] == ':') {
            res.push_back(make_pair(curr, i - curr - 1));
            curr = ++i + 1; // next is space
        }
    }
    res.push_back(make_pair(curr, i - curr));
    return res;
}

void output(string name, int spaces) {
    Person& p = people[name];
    cout << string(spaces, ' ') << name;
    if (p.birth != "")
        cout << ' ' << p.birth << " -";
        if (p.death != "")
            cout << ' ' << p.death;
    cout << '\n';
}

void ancestors(string name, int spaces = 2) {
    for (string parent : people[name].parents) {
        output(parent, spaces);
        ancestors(parent, spaces + 2);
    }
}

void descendants(string name, int spaces = 2) {
    for (string child : people[name].children) {
        output(child, spaces);
        descendants(child, spaces + 2);
    }
}

int main() {
    string command, input;
    bool firstOutput = true;
    
    while (cin >> command) {
        if (command == "QUIT")
            break;

        getline(cin, input);

        if (command == "BIRTH") {
            vector<pair<int, int>> pos = parse(input);
            string name = input.substr(pos[0].first, pos[0].second);
            Person& child = people[name];

            child.birth = input.substr(pos[1].first, pos[1].second);
            string mother = input.substr(pos[2].first, pos[2].second);
            string father = input.substr(pos[3].first, pos[3].second);
            child.parents.insert(mother);
            child.parents.insert(father);
            people[mother].children.insert(name);
            people[father].children.insert(name);

        } else if (command == "DEATH") {
            vector<pair<int, int>> pos = parse(input);
            people[input.substr(pos[0].first, pos[0].second)].death = input.substr(pos[1].first, pos[1].second);

        } else if (command == "ANCESTORS") {
            if (!firstOutput)
                cout << '\n';
            else 
                firstOutput = false;

            string name = input.substr(1);
            cout << "ANCESTORS of " << name << '\n';
            ancestors(name);
            

        } else if (command == "DESCENDANTS") {
            if (!firstOutput)
                cout << '\n';
            else 
                firstOutput = false;

            string name = input.substr(1);
            cout << "DESCENDANTS of " << name << '\n';
            descendants(name);
        }
    }
    return 0;
}