#include <bits/stdc++.h>

using namespace std;

int main() {
    // pointer to int is created, and pointing to some garbage address
    // int *p = 0;
    // cout << *p << endl;

    /*
    int i = 5;
    int *p = &i;
    cout << p << endl;
    cout << *p << endl;

    int *q = 0;
    q = &i;

    cout << q << endl;
    cout << *q << endl;
    */

    int num = 5;
    int a = num;
    cout << "a Before " << num << endl;
    a++;
    cout << "a After " << num << endl;

    int *p = &num;
    cout << "Before " << num << endl;
    (*p)++;
    cout << "After " << num << endl;

    // copying a pointer
    int *q = p;
    cout << p << " - " << q << endl;
    cout << *p << " - " << *q << endl;

    // important concept
    int i = 3;
    int *t = &i;
    cout << (*t)++ << endl;
    *t += 1;
    cout << *t << endl;
    cout << "Before t " << t << endl;
    t += 1;
    cout << "After t " << t << endl;

    return 0;
}