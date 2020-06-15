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
  int a, ans;

  for (int i = 1; i <= 5; i++)
  {
    cin >> a;
    if (a == 0)
      ans = i;
  }
  cout << ans << endl;
}