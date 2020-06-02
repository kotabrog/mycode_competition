#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t a = 2, b = 1, ans, c;
  int n;

  cin >> n;
  if (n == 1)
    ans = b;
  else
  {
    for (int i = 0; i < n - 1; i++)
    {
      c = a + b;
      a = b;
      b = c;
    }
    ans = c;
  }
  cout << ans << endl;
}