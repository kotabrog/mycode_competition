#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int gcd(int a,int b){return (a%b==0?b:gcd(b, a%b));}
int lcm(int a,int b){return a*b/gcd(a, b);}

int main()
{
  int n, m, max_l = 0, min_r, l, r;

  cin >> n >> m;
  min_r = n;
  for (int i = 0; i < m; i++)
  {
    cin >> l >> r;
    max_l = max(l, max_l);
    min_r = min(r, min_r);
  }
  cout << max(min_r - max_l + 1, 0) << endl;
}