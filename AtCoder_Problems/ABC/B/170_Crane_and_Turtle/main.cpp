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
  int x, y;
  bool flag = false;

  cin >> x >> y;
  for (int i = 0; i * 2 <= y; i++)
  {
    for (int j = 0; i * 2 + 4 * j <= y; j++)
    {
      if (2 * i + 4 * j == y && i + j == x)
        flag = true;
    }
  }
  cout << (flag ? "Yes" : "No") << endl;
}