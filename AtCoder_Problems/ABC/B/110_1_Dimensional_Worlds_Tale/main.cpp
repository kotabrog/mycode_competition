#include <bits/stdc++.h>
using namespace std;

int main()
{ 
  int n, m, x, y, max_x = -100, min_y = 100, a;
  bool flag;

  cin >> n >> m >> x >> y;
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    max_x = max(a, max_x);
  }
  for (int i = 0; i < m; i++)
  {
    cin >> a;
    min_y = min(a, min_y);
  }
  cout << (max(x, max_x) < min(y, min_y) ? "No War" : "War") << endl;
}