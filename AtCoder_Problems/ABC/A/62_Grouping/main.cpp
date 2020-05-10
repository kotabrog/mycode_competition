#include <bits/stdc++.h>
using namespace std;

int main()
{
  int x, y;
  set<int> a{1, 3, 5, 7, 8, 10, 12};
  set<int> b{4, 6, 9, 11};
  set<int> c{2};
  cin >> x >> y;
  cout << ((a.count(x) && a.count(y)) || (b.count(x) && b.count(y)) || (c.count(x) && c.count(y)) ? "Yes" : "No") << endl;
}
