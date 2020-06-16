#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int gcd(int a,int b){return (a%b==0?b:gcd(b, a%b));}
int lcm(int a,int b){return a*b/gcd(a, b);}

int main()
{
  int n, sum_s = 0, ans = 0;
  vector<int> s(100);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
    sum_s += s[i];
  }
  sort(s.begin(), s.begin() + n - 1);
  if (sum_s % 10 != 0)
  {
    cout << sum_s << endl;
    return (0);
  }
  for (int i = 0; i < n; i++)
  {
    if ((sum_s - s[i]) % 10 != 0)
    {
      ans = sum_s - s[i];
      break;
    }
  }
  cout << ans << endl;
}