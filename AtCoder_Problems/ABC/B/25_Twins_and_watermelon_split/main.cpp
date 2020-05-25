#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, a, b, d, pm, x = 0;
  string s;

  cin >> n >> a >> b;
  for (int i = 0; i < n; i++)
  {
    cin >> s >> d;
    if (s == "West")
      pm = -1;
    else
      pm = 1;
    x += pm * min(b, max(a, d));
  }
  if (x == 0)
    cout << 0 << endl;
  else
    cout << (x < 0 ? "West " : "East ") << abs(x) << endl;
}
