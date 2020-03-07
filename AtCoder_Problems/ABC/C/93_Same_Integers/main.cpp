#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, b, c, x1, x2, x3, ans;

  cin >> a >> b >> c;
  x1 = max(max(a, b), c);
  x3 = min(min(a, b), c);
  if (max(b, c) == x1 && min(b, c) == x3)
    x2 = a;
  else if (max(a, c) == x1 && min(a, c) == x3)
    x2 = b;
  else
    x2 = c;
  ans = x1 - x2;
  x3 += ans;
  if (x3 % 2 == x1 % 2)
    ans += (x1 - x3) / 2;
  else
    ans += (x1 - x3 + 1) / 2 + 1;
  cout << ans << endl;
}