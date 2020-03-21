#include <bits/stdc++.h>
using namespace std;

int main()
{
  int D, G, ans = 10000, c, count, sum, N = 0;
  vector<vector<int>> a(10, vector<int>(2, 0));
  bool flag;

  cin >> D >> G;
  for (int i = 0; i < D; i++)
  {
    cin >> a[i][0] >> c;
    a[i][1] = a[i][0] * 100 * (i + 1) + c;
  }
  for (int i = 1; i <= D; i++)
  {
    for (int tmp = 1; tmp < (1 << D); tmp++)
    {
      bitset<10> s(tmp);
      sum = 0;
      count = 0;
      for (int j = 0; j < D; j++)
      {
        if (s.test(j))
        {
          sum += a[j][1];
          count += a[j][0];
        }
      }
      if (sum < G)
        continue;
      ans = min(ans, count);
      for (int j = 0; j < D; j++)
      {
        if (s.test(j))
        {
          if (sum - a[j][1] < G)
            ans = min(ans, count - a[j][0] + (G - (sum - a[j][1]) - 1) / ((j + 1) * 100) + 1);
        }
      }
    }
  }
  cout << ans << endl;
}