#include <bits/stdc++.h>

using namespace std;

void update1(int n) {
    n++;
}

void update2(int& n) {
    n++;
}

int& func(int a) {
    int num = a;
    int& ans = num;
    return ans;
}

int* fun(int n) {
    int* ptr = &n;
    return ptr;
}

int main() {
    /*
    int i = 5;
    // creating a reference variable
    int& j = i;

    cout << i << endl;
    i++;
    cout << i << endl;
    j++;
    cout << i << endl;
    */

    int n = 5;
    cout << "Before " << n << endl;
    update2(n);
    cout << "After " << n << endl;

    func(n);
    fun(n);
    return 0;
}