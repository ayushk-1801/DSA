#include <bits/stdc++.h>
using namespace std;

int score = 15;

void a(int& i) {
    cout << score << " in a" << endl;
}

void b(int& i) {
    cout << score << " in b" << endl;
}

int main() {
    int i = 5;
    a(i);
    b(i);

    return 0;
}