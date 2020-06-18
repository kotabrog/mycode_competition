#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int gcd(int a,int b){return (a%b==0?b:gcd(b, a%b));}
int lcm(int a,int b){return a*b/gcd(a, b);}

int main()
{
  int n, k, ans = 1000000000;
  vector<int> h(100000);

  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> h[i];
  sort(h.begin(), h.begin() + n);
  for (int i = 0; i < n - k + 1; i++)
    ans = min(ans, h[i + k - 1] - h[i]);
  cout << ans << endl;
}