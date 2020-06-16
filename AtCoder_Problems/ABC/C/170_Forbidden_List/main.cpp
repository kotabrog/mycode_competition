#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int gcd(int a,int b){return (a%b==0?b:gcd(b, a%b));}
int lcm(int a,int b){return a*b/gcd(a, b);}

int main()
{
  int x, n, tmp = 1, ans = 200;
  vector<int> p(100);
  bool flag = true;

  cin >> x >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> p[i];
    if (p[i] == x)
      flag = false;
  }
  if (flag)
    ans = x;
  while (ans == 200)
  {
    flag = true;
    for (int i = 0; i < n; i++)
    {
      if (x + tmp == p[i])
        flag = false;
    }
    if (flag)
      ans = x + tmp;
    flag = true;
    for (int i = 0; i < n; i++)
    {
      if (x - tmp == p[i])
        flag = false;
    }
    if (flag)
      ans = x - tmp;
    tmp++;
  }
  cout << ans << endl;
}