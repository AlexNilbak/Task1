#include "Vector.h"
#include "Vector0.h"
using namespace std;

void AutoTest() {
    double a[1];
    double b[1];
    a[0] = 0;
    b[0] = 1;
    Vector0 A(a, 1);
    Vector0 B(b, 1);
    Vector0 C;
    C = A + B;
    double d = A * B;
    if (C.vector()[0] == 1 && d == 0) {
        cout << "Autotest passed" << endl;
    }
    else {
        cout << "Autotest failed" << endl;
    }
}