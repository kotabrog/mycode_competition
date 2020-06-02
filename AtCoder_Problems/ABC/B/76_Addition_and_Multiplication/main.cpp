#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, k, ans = 1;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    if (ans < k)
      ans *= 2;
    else
      ans += k;
  }
  cout << ans << endl;
}