#include <bits/stdc++.h>
using namespace std;

int main() {
    deque<int> d;
    d.push_front(12);
    d.push_back(14);

    cout << d.front() << endl;
    cout << d.back() << endl;

    d.pop_front();

    cout << d.front() << endl;
    cout << d.back() << endl;

    d.pop_back();
    if (d.empty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }

    /*
    queue<int> q;

    q.push(11);
    cout<<"Front of queue is : "<<q.front()<<endl;
    q.push(15);
    cout<<"Front of queue is : "<<q.front()<<endl;
    q.push(13);

    cout << "Size of queue is : " << q.size() << endl;

    q.pop();

    cout << "Size of queue is : " << q.size() << endl;

    if (q.empty())
        cout << "Queue is empty" << endl;
    else
        cout << "Queue is not empty" << endl;
    */

    return 0;
}