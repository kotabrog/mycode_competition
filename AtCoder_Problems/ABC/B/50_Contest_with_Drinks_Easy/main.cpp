#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m, p, x, t_sum = 0;
  vector<int> t(100);
  vector<int> ans(100);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> t[i];
    t_sum += t[i];
  }
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> p >> x;
    ans[i] = t_sum - t[p - 1] + x;
  }
  for (int i = 0; i < m; i++)
    cout << ans[i] << endl;

}