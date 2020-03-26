#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> a(12, vector<char>(12, '.'));

void dfs(int y, int x, int *flag)
{
  if (a[y][x] == '#' || (*flag != 1 && a[y][x] == 'x') || \
      (*flag != 2 && a[y][x] == '1') || a[y][x] == '.')
    return ;
  if (*flag == 1 && a[y][x] == 'x')
  {
    if (a[y + 1][x] == '#' || a[y - 1][x] == '#' || \
        a[y][x + 1] == '#' || a[y][x - 1] == '#')
      a[y][x] = '1';
    return ;
  }
  if (*flag == 2 && a[y][x] == '1')
  {
    a[y][x] = '2';
    return ;
  }
  if (*flag == 3 && a[y][x] == '2')
  {
    a[y][x] = '3';
    return ;
  }
  if (*flag == 0)
    a[y][x] = '#';
  else
    a[y][x] = '.';
  dfs(y - 1, x, flag);
  dfs(y + 1, x, flag);
  dfs(y, x - 1, flag);
  dfs(y, x + 1, flag);
}

int main()
{
  int flag = 0;

  for (int i = 1; i <= 10; i++)
  {
    for (int j = 1; j <= 10; j++)
      cin >> a[i][j];
  }
  for (int i = 1; i <= 10; i++)
  {
    if (flag > 3)
      break;
    for (int j = 1; j <= 10; j++)
    {
      if (flag > 3)
        break;
      if (a[i][j] == 'o')
      {
        dfs(i, j, &flag);
        flag++;
      }
    }
  }
  for (int i = 1; i <= 10; i++)
  {
    if (flag <= 1)
      break;
    for (int j = 1; j <= 10; j++)
    {
      if (flag <= 1)
        break;
      if (a[i][j] == '0' + flag - 1)
        flag = -1;
    }
  }
  if (flag <= 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}