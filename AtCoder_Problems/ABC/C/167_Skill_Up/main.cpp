#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m, x;
  vector<vector<int>> a(13, vector<int>(13));
  vector<int> sum_temp(13);
  vector<int> ans(13);
  bool flag;

  cin >> n >> m >> x;
  ans[0] = 100000000;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j <= m; j++)
      cin >> a[i][j];
  }
  for (int tmp = 0; tmp < (1 << n); tmp++)
  {
    bitset<12> s(tmp);
    for (int i = 0; i <= m; i++)
      sum_temp[i] = 0;
    flag = true;
    for (int i = 1; i <= n; i++)
    {
      if (s.test(i - 1))
      {
        for (int j = 0; j <= m; j++)
        {
          sum_temp[j] += a[i][j];
        }
      }
    }
    for (int i = 1; i <= m; i++)
    {
      if (sum_temp[i] < x)
      {
        flag = false;
        break;
      }
    }
    if (flag)
    {
      if (sum_temp[0] < ans[0])
      {
        for (int i = 0; i <= m; i++)
          ans[i] = sum_temp[i];
      }
    }
  }
  if (ans[0] != 100000000)
    cout << ans[0] << endl;
  else
    cout << -1 << endl;
}