#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, b, c, k, ans;
  cin >> a >> b >> c >> k;
  ans = min(a, k);
  k -= a;
  if (0 < k)
    k -= b;
  if (0 < k)
  {
    ans -= k;
  }
  cout << ans << endl;
}