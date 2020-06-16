#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int gcd(int a,int b){return (a%b==0?b:gcd(b, a%b));}
int lcm(int a,int b){return a*b/gcd(a, b);}

int main()
{
  int n, a, ans = 0;
  
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    while (a % 2 == 0)
    {
      ans++;
      a /= 2;
    }
  }
  cout << ans << endl;
}