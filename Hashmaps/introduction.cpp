#include <bits/stdc++.h>
#include <utility>
using namespace std;

int main() {
  map<string, int> m;

  // 1
  pair<string, int> p = make_pair("ayush", 3);
  m.insert(p);

  // 2
  pair<string, int> q("kumar", 2);
  m.insert(q);

  // 3
  m["anand"] = 1;

  // updation
  m["anand"] = 2;

  // search
  cout << m["kumar"] << endl;
  cout << m.at("ayush") << endl;
  cout << m["unknownkey"] << endl;
  cout << m.at("unknownkey") << endl;

  // size
  cout << m.size() << endl;

  // check presence
  cout << m.count("bro") << endl;

  // erase
  m.erase("anand");
  cout << m.size() << endl;

  // iterator
  map<string, int>::iterator it = m.begin();

  while (it != m.end()) {
    cout << it->first << " -> " << it->second << endl;
    it++;
  }
  return 0;
}
