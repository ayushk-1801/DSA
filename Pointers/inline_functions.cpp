#include <bits/stdc++.h>
using namespace std;

inline int getMax(int& a, int& b) {
    return (a > b) ? a : b;
}

int main() {
    int a = 1, b = 2;
    int ans = 0;

    ans = getMax(a, b);
    cout << ans << endl;

    a += 3;
    b += 1;

    ans = getMax(a, b);
    cout << ans;

    return 0;
}