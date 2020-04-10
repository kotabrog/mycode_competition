#include <bits/stdc++.h>
using namespace std;



int main()
{
  int H, W, N, m, n, ans = 0;
  vector<vector<char>> c(1002, vector<char>(1002, 'X'));
  vector<vector<int>> count(1002, vector<int>(1002, 0));
  pair<int, int> tmp;
  queue<pair<int, int>> q;

  cin >> H >> W >> N;
  for (int i = 1; i <= H; i++)
  {
    for (int j = 1; j <= W; j++)
    {
      cin >> c[i][j];
      if (c[i][j] == 'S')
      {
        tmp.first = i;
        tmp.second = j;
        q.push(tmp);
      }
    }
  }
  for (int i = 1; i <= N; i++)
  {
    if (1 < i)
    {
      while (!q.empty())
        q.pop();
      for (int j = 1; j <= H; j++)
      {
        for (int k = 1; k <= W; k++)
          count[j][k] = 0;
      }
      q.push(tmp);
    }
    while (1)
    {
      tmp = q.front();
      q.pop();
      m = tmp.first;
      n = tmp.second;
      if (c[m][n] == '0' + i)
        break;
      if (c[m + 1][n] != 'X' && !count[m + 1][n])
      {
        q.push(make_pair(m + 1, n));
        count[m + 1][n] = count[m][n] + 1;
      }
      if (c[m - 1][n] != 'X' && !count[m - 1][n])
      {
        q.push(make_pair(m - 1, n));
        count[m - 1][n] = count[m][n] + 1;
      }
      if (c[m][n - 1] != 'X' && !count[m][n - 1])
      {
        q.push(make_pair(m, n - 1));
        count[m][n - 1] = count[m][n] + 1;
      }
      if (c[m][n + 1] != 'X' && !count[m][n + 1])
      {
        q.push(make_pair(m, n + 1));
        count[m][n + 1] = count[m][n] + 1;
      }
    }
    ans += count[m][n];
  }
  cout << ans << endl;
}
