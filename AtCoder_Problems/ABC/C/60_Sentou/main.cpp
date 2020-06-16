#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int gcd(int a,int b){return (a%b==0?b:gcd(b, a%b));}
int lcm(int a,int b){return a*b/gcd(a, b);}

int main()
{
  int n;
  int64_t t, tmp_a, tmp_b, ans = 0;

  cin >> n >> t;
  for (int i = 0; i < n; i++)
  {
    cin >> tmp_b;
    if (i == 0)
    {
      tmp_a = tmp_b;
      continue;
    }
    ans += min(t, tmp_b - tmp_a);
    tmp_a = tmp_b;
  }
  ans += t;
  cout << ans << endl;
}