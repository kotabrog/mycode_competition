#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int gcd(int a,int b){return (a%b==0?b:gcd(b, a%b));}
int lcm(int a,int b){return a*b/gcd(a, b);}

int main()
{
  int64_t n, ans = 0, tmp;
  vector<int> a(100001), b(100000);

  cin >> n;
  for (int i = 0; i < n + 1; i++)
    cin >> a[i];
  for (int j = 0; j < n; j++)
    cin >> b[j];
  for (int i = 0; i < n; i++)
  {
    tmp = min(b[i], a[i]);
    b[i] -= tmp;
    ans += tmp;
    tmp = min(b[i], a[i + 1]);
    a[i + 1] -= tmp;
    ans += tmp;
  }
  cout << ans << endl;
}