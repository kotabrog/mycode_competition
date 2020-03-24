#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, M, x, y, ans = 0;
  vector<vector<bool>> xy(12, vector<bool>(12, false));
  bool flag;

  cin >> N >> M;
  for (int i = 0; i < M; i++)
  {
    cin >> x >> y;
    xy[x - 1][y - 1] = true;
    xy[y - 1][x - 1] = true;
  }
  for (int tmp = 1; tmp < (1 << N); tmp++)
  {
    bitset<12> s(tmp);
    flag = true;
    for (int i = 0; i < N; i++)
    {
      if (s.test(i))
      {
        for (int j = i + 1; j < N; j++)
        {
          if (s.test(j))
          {
            if (!xy[i][j])
            {
              flag = false;
              break;
            }
          }
        }
      }
      if (!flag)
        break;
    }
    if (flag)
      ans = max(ans, (int)s.count());
  }
  cout << ans << endl;
}