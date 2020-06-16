#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int gcd(int a,int b){return (a%b==0?b:gcd(b, a%b));}
int lcm(int a,int b){return a*b/gcd(a, b);}

int main()
{
  int64_t x, y;
  int ans = 1;

  cin >> x >> y;
  while (x <= (y / 2))
  {
    x *= 2;
    ans++;
  }
  cout << ans << endl;
}