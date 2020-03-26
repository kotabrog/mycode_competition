#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> c(502, vector<char>(502, '#'));

void dfs(int y, int x, bool *flag)
{
  if (*flag || c[y][x] == '#')
    return ;
  if (c[y][x] == 'g')
  {
    *flag = true;
    return ;
  }
  c[y][x] = '#';
  dfs(y - 1, x, flag);
  dfs(y + 1, x, flag);
  dfs(y, x - 1, flag);
  dfs(y, x + 1, flag);
}

int main()
{
  int H, W;
  vector<int> sc(2);
  bool flag = false;

  cin >> H >> W;
  for (int i = 1; i <= H; i++)
  {
    for (int j = 1; j <= W; j++)
    {
      cin >> c[i][j];
      if (c[i][j] == 's')
      {
        sc[0] = i;
        sc[1] = j;
      }
    }
  }
  dfs(sc[0], sc[1], &flag);
  if (flag)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}