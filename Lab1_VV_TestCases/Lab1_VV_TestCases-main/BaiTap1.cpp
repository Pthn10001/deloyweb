
#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

int solveQuartic(double a, double b, double c, double x[]) {
    if (a == 0 && b == 0 && c == 0) return -1;
    if (a == 0 && b == 0) return 0;
    if (a == 0) {
        double y = -c / b;
        if (y < 0) return 0;
        x[0] = sqrt(y);
        x[1] = -sqrt(y);
        return 2;
    }
    double delta = b*b - 4*a*c;
    if (delta < 0) return 0;
    double y1 = (-b + sqrt(delta)) / (2*a);
    double y2 = (-b - sqrt(delta)) / (2*a);
    int count = 0;
    if (y1 >= 0) {
        x[count++] = sqrt(y1);
        x[count++] = -sqrt(y1);
    }
    if (y2 >= 0 && y2 != y1) {
        x[count++] = sqrt(y2);
        x[count++] = -sqrt(y2);
    }
    return count;
}

int main() {
    double x[4];
    int n;
    n = solveQuartic(0,0,0,x);
    assert(n == -1);
    n = solveQuartic(0,0,1,x);
    assert(n == 0);
    n = solveQuartic(0,1,-4,x);
    assert(n == 2);
    n = solveQuartic(1,0,1,x);
    assert(n == 0);
    n = solveQuartic(1,-5,4,x);
    assert(n == 4);
    cout << "All tests passed!" << endl;
    return 0;
}
