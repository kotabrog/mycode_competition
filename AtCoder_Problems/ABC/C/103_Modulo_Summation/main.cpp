#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int64_t gcd(int64_t a,int64_t b){return (a%b==0?b:gcd(b, a%b));}
int64_t lcm(int64_t a,int64_t b){return a*b/gcd(a, b);}

int main()
{
  int n, a, ans = 0;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    ans += a - 1;
  }
  cout << ans << endl;
}