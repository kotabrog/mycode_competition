#include <bits/stdc++.h>
using namespace std;

//より簡潔に

vector<vector<char>> a(12, vector<char>(12, 'x'));
vector<vector<bool>> a_flag(12, vector<bool>(12, false));

void dfs(int y, int x)
{
  if (a[y][x] == 'x' || a_flag[y][x])
    return ;
  a_flag[y][x] = true;
  dfs(y - 1, x);
  dfs(y + 1, x);
  dfs(y, x - 1);
  dfs(y, x + 1);
}

int main()
{
  bool flag;

  for (int i = 1; i <= 10; i++)
  {
    for (int j = 1; j <= 10; j++)
      cin >> a[i][j];
  }
  for (int i = 1; i <= 10; i++)
  {
    for (int j = 1; j <= 10; j++)
    {
      if (a[i][j] == 'x')
      {
        a[i][j] = 'o';
        dfs(i, j);
        flag = true;
        for (int i = 1; i <= 10; i++)
        {
          for (int j = 1; j <= 10; j++)
          {
            if (!a_flag[i][j] && a[i][j] == 'o')
              flag = false;
            a_flag[i][j] = false;
          }
        }
        if (flag)
        {
          cout << "YES" << endl;
          return (0);
        }
        a[i][j] = 'x';
      }
    }
  }
  cout << "NO" << endl;
}