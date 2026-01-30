#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    int e, f, g, h;

    // First matrix
    cout << "Enter elements of first matrix:" << endl;
    cin >> a >> b;
    cin >> c >> d;

    // Second matrix
    cout << "Enter elements of second matrix:" << endl;
    cin >> e >> f;
    cin >> g >> h;

    // Strassen's 7 multiplications
    int M1 = (a + d) * (e + h);
    int M2 = (c + d) * e;
    int M3 = a * (f - h);
    int M4 = d * (g - e);
    int M5 = (a + b) * h;
    int M6 = (c - a) * (e + f);
    int M7 = (b - d) * (g + h);

    // Result matrix
    int C11 = M1 + M4 - M5 + M7;
    int C12 = M3 + M5;
    int C21 = M2 + M4;
    int C22 = M1 - M2 + M3 + M6;

    // Output
    cout << "Resultant Matrix:" << endl;
    cout << C11 << " " << C12 << endl;
    cout << C21 << " " << C22 << endl;

    return 0;
}