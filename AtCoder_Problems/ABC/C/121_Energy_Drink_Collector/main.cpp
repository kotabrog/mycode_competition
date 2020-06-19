#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int gcd(int a,int b){return (a%b==0?b:gcd(b, a%b));}
int lcm(int a,int b){return a*b/gcd(a, b);}

int main()
{
  int n, m, a, b;
  vector<pair<int, int>> ab;
  int64_t ans = 0;

  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    cin >> a >> b;
    ab.push_back(make_pair(a, b));
  }
  sort(ab.begin(), ab.end());
  for (int i = 0; i < n; i++)
  {
    ans += (int64_t)ab[i].first * min(m, ab[i].second);
    m -= min(m, ab[i].second);
    if (m == 0)
      break;
  }
  cout << ans << endl;
}