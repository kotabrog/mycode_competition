#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  double a, b;

  cin >> n >> m;
  n %= 12;
  a = (n + (double)m / 60) * 30;
  b = m * 6;
  cout << min(abs(a - b), 360 - abs(a - b)) << endl;
}
