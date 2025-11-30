#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;

    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {

    cout << gcd(12, 10) << endl;    // 2
    cout << gcd(80, 120) << endl;   // 40

    return 0;
}
