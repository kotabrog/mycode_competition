#include <bits/stdc++.h>
using namespace std;

int main()
{
  int A, B, C, X, Y, r;
  int ans = 0;

  cin >> A >> B >> C >> X >> Y;
  r = X - Y;
  if (2 * C <= A && r >= 0)
  {
    if (A <= C)
      ans = 2 * C * r + A * min(r, X - r) + min(2 * C, A + B) * max(X - 2 * r, 0) / 2;
    else
      ans = 2 * C * r + min(2 * C, A + B) * (X + Y - r) / 2;
  }
  else if (2 * C <= B && r < 0)
  {
    if (B <= C)
      ans = 2 * C * abs(r) + B * min(r, Y - abs(r)) + min(2 * C, A + B) * max(Y - 2 * abs(r), 0) / 2;
    else
      ans = 2 * C * abs(r) + min(2 * C, A + B) * (X + Y - abs(r)) / 2;
  }
  else if (r >= 0)
    ans = A * r + min(2 * C, A + B) * (X + Y - r) / 2;
  else
    ans = B * abs(r) + min(2 * C, A + B) * (X + Y - abs(r)) / 2;
  cout << ans << endl;
}