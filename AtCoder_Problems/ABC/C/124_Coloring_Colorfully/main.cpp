#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int gcd(int a,int b){return (a%b==0?b:gcd(b, a%b));}
int lcm(int a,int b){return a*b/gcd(a, b);}

int main()
{
  string s;
  int ans = 0, tmp = 0;

  cin >> s;
  for (int i = 0; i < s.size(); i++)
  {
    if (i % 2 == 0)
    {
      if (s[i] == '1')
        ans++;
    }
    else
    {
      if (s[i] == '0')
        ans++;
    }
  }
  for (int i = 0; i < s.size(); i++)
  {
    if (i % 2 == 1)
    {
      if (s[i] == '1')
        tmp++;
    }
    else
    {
      if (s[i] == '0')
        tmp++;
    }
  }
  cout << min(ans, tmp) << endl;
}