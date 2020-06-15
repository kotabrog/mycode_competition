#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int gcd(int a, int b)
{
  if (a%b == 0)
    return(b);
  else
    return(gcd(b, a%b));
}

int lcm(int a, int b)
{
  return a * b / gcd(a, b);
}

int main()
{
  int k, ans = 0;

  cin >> k;
  for (int i = 1; i <= k; i++)
  {
    for (int j = 1; j <= k; j++)
    {
      for (int m = 1; m <= k; m++)
        ans += gcd(i, gcd(j, m));
    }
  }
  cout << ans << endl;
}