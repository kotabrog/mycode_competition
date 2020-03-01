#include <bits/stdc++.h>
using namespace std;

int main()
{
  int A, B, C, X, Y, r, AorB;
  int ans = 0;
  bool flagA = true;

  cin >> A >> B >> C >> X >> Y;
  r = X - Y;
  if (r < 0)
    flagA = false;
  AorB = (A * flagA + B * (1 - flagA));
  if (2 * C <= AorB)
  {
    if (AorB <= C)
      ans = 2 * C * abs(r) + AorB * min(r, max(X, Y) - abs(r)) + min(2 * C, A + B) * max(max(X, Y) - 2 * abs(r), 0) / 2;
    else
      ans = 2 * C * abs(r) + min(2 * C, A + B) * (X + Y - abs(r)) / 2;
  }
  else
    ans = AorB * abs(r) + min(2 * C, A + B) * (X + Y - abs(r)) / 2;
  cout << ans << endl;
}