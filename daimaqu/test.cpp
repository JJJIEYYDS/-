#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int h, r;
    cin >> h >> r;
    double v = 3.14 * r * r * h;
    double t = 20000 / v;
    t = ceil(t);
    cout << t << endl;
    return 0;
}