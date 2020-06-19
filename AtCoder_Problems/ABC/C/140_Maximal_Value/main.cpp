#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int gcd(int a,int b){return (a%b==0?b:gcd(b, a%b));}
int lcm(int a,int b){return a*b/gcd(a, b);}

int main()
{
  int n, ans = 0;
  vector<int> b(100);

  cin >> n;
  for (int i = 0; i < n - 1; i++)
    cin >> b[i];
  for (int i = 0; i < n - 1; i++)
  {
    if (i == 0)
      ans += b[0];
    else
      ans += min(b[i - 1], b[i]);
  }
  ans += b[n - 2];
  cout << ans << endl;
}