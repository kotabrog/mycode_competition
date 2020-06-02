#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, k, x, ans = 0;

  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    ans += 2 * min(x, abs(k - x));
  }
  cout << ans << endl;
}