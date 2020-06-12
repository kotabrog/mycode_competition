#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t x, ans = 0, m = 100;

  cin >> x;
  while (x > m)
  {
    ans++;
    m += m * 0.01;
  }
  cout << ans << endl;
}