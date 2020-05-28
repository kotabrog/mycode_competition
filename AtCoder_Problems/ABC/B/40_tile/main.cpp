#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, ans = 100000;
  
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    ans = min(ans, abs((n / i) - i) + n - (n / i) * i);
    if (n < i * i)
      break;
  }
  cout << ans << endl;
}