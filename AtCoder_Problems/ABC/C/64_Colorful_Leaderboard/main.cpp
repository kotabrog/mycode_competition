#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int gcd(int a,int b){return (a%b==0?b:gcd(b, a%b));}
int lcm(int a,int b){return a*b/gcd(a, b);}

bool in_num(int a, int b, int c)
{
  if (b <= a && a <= c)
    return true;
  else
    return false;
}

int rate(int a)
{
  if (in_num(a, 1, 399))
    return 0;
  else if (in_num(a, 400, 799))
    return 1;
  else if (in_num(a, 800, 1199))
    return 2;
  else if (in_num(a, 1200, 1599))
    return 3;
  else if (in_num(a, 1600, 1999))
    return 4;
  else if (in_num(a, 2000, 2399))
    return 5;
  else if (in_num(a, 2400, 2799))
    return 6;
  else if (in_num(a, 2800, 3199))
    return 7;
  else
    return 8;
}

int main()
{
  int n, a, count_f = 0, tmp, ans = 0;
  vector<bool> flag(8, false);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    tmp = rate(a);
    if (tmp == 8)
      count_f++;
    else
    {
      if (!flag[tmp])
      {
        flag[tmp] = true;
        ans++;
      }
    }
  }
  cout << max(1, ans) << ' ' << ans + count_f << endl;
}