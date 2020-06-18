#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int gcd(int a,int b){return (a%b==0?b:gcd(b, a%b));}
int lcm(int a,int b){return a*b/gcd(a, b);}

int main()
{
  string s;
  int ans = 0, n, i = 1;

  cin >> s;
  n = s.size();
  while (s.size() > i)
  {
    if (i == 0)
    {
      i++;
      continue;
    }
    if (s[i] != s[i - 1])
    {
      s.erase(i - 1, 2);
      ans += 2;
      i--;
    }
    else
      i++;
  }
  cout << ans << endl;
}