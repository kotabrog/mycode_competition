#include <bits/stdc++.h>
using namespace std;

int main()
{ 
  int a, b, c, d, disx, disy, pm_start;
  vector<vector<int>> pm{{1, 1}, {-1, 1}, {-1, -1}, {1, -1}};
  
  cin >> a >> b >> c >> d;
  disx = abs(a - c);
  disy = abs(b - d);
  if (c - a >= 0)
  {
    if (d - b >= 0)
      pm_start = 0;
    else
      pm_start = 3;
  }
  else
  {
    if (d - b >= 0)
      pm_start = 1;
    else
      pm_start = 2;
  }
  cout << c + pm[(pm_start + 1) % 4][0] * disy << " " \
      << d + pm[(pm_start + 1) % 4][1] * disx << " " \
      << c + pm[(pm_start + 1) % 4][0] * disy + pm[(pm_start + 2) % 4][0] * disx<< " " \
      << d + pm[(pm_start + 1) % 4][1] * disx + pm[(pm_start + 2) % 4][1] * disy<< endl;
// ++ -+ -- +- 
// ab ba ab ba
}