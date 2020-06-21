#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int gcd(int a,int b){return (a%b==0?b:gcd(b, a%b));}
int lcm(int a,int b){return a*b/gcd(a, b);}

int main()
{
  int n, k, ans = 0;
  vector<int> p(1000);

  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> p[i];
  sort(p.begin(), p.begin() + n);
  for (int i = 0; i < k; i++)
    ans += p[i];
  cout << ans << endl;
}