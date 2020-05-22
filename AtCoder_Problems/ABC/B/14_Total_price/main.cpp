#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, x, ans=0, a;
  cin >> n >> x;
  bitset<20> b(x);
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    if (b[i])
      ans += a;
  }
  cout << ans << endl;
}
