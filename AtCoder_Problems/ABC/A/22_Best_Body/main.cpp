#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, s, t, ans = 0, w, a;
  cin >> n >> s >> t >> w;
  if (s <= w && w <= t)
    ans++;
  for (int i = 1; i < n; i++)
  {
    cin >> a;
    w += a;
    if (s <= w && w <= t)
      ans++;
  }
  cout << ans << endl;
}
