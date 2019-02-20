#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

struct point {
    double x, y;

    point(double a, double b) {
        x = a;
        y = b;
    }
};

double T;
vector<point> points;
const double cos60 = 1.0/2.0;
const double sin60 = sqrt(3)/2.0;

double dist(point a, point b) {
    return sqrt(pow(a.x - b.x, 2.0) + pow(a.y - b.y, 2.0));
}

void fractal(point A, point B) {
    if (dist(A, B)/2.0 > T) {
        point C(A.x + (B.x - A.x)/4, A.y + (B.y - A.y)/4);
        point D(A.x + 3*(B.x - A.x)/4, A.y + 3*(B.y - A.y)/4);
        double vectorX = D.x - C.x, vectorY = D.y - C.y;

        /*
        Rotate 60 degrees
        |cos60  -sin60| |vectorX|
        |sin60  cos60 | |vectorY|
        */
        point E(C.x + vectorX*cos60 - vectorY*sin60, C.y + vectorX*sin60 + vectorY*cos60);
        
        points.push_back(C);
        points.push_back(D);
        points.push_back(E);

        fractal(C, E);
        fractal(E, D);
    }
}

auto cmp = [](const point & a, const point & b) {
    if (abs(a.x - b.x) >= 1e-8)
        return a.x < b.x;
    else
        return a.y < b.y;
};

int main() {
    double AX, AY, BX, BY;
    int t = 0;
    while (cin >> AX >> AY >> BX >> BY >> T) {
        if (T < 1)
            break;
        points.clear();

        point A(AX, AY);
        point B(BX, BY);
        points.push_back(A);
        points.push_back(B);
        fractal(A, B);
        
        sort(points.begin(), points.end(), cmp);
        cout << "Case " << ++t << ":\n";
        cout << points.size() << '\n';
        cout << setprecision (5) << fixed;
        for (point p : points) {
            cout << p.x << ' ' << p.y << '\n';
        }
    }

    return 0;
}