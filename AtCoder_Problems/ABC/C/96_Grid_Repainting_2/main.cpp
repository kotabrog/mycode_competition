#include <bits/stdc++.h>
using namespace std;

int main()
{
  int H, W;
  vector<vector<char>> s(50, vector<char>(50, '.'));
  bool flag = true;

  cin >> H >> W;
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
      cin >> s[i][j];
  }
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if (s[i][j] == '.')
        continue;
      if (i == 0 && j == 0 && i == H - 1 && j == W - 1)
        flag = false;
      else if (i == 0 && j == 0 && i == H - 1)
      {
        if (s[i][j + 1] != '#')
          flag = false;
      }
      else if (i == 0 && j == 0 && j == W - 1)
      {
        if (s[i + 1][j] != '#')
          flag = false;
      }
      else if (i == 0 && j == 0)
      {
        if (s[i + 1][j] != '#' && s[i][j + 1] != '#')
          flag = false;
      }
      else if (i == 0 && j == W - 1)
      {
        if (s[i + 1][j] != '#' && s[i][j - 1] != '#')
          flag = false;
      }
      else if (i == H - 1 && j == 0)
      {
        if (s[i - 1][j] != '#' && s[i][j + 1] != '#')
          flag = false;
      }
      else if (i == H - 1 && j == W - 1)
      {
        if (s[i - 1][j] != '#' && s[i][j - 1] != '#')
          flag = false;
      }
      else if (i == 0)
      {
        if (s[i + 1][j] != '#' && s[i][j + 1] != '#' && s[i][j - 1] != '#')
          flag = false;
      }
      else if (i == H - 1)
      {
        if (s[i - 1][j] != '#' && s[i][j + 1] != '#' && s[i][j - 1] != '#')
          flag = false;
      }
      else if (j == 0)
      {
        if (s[i + 1][j] != '#' && s[i - 1][j] != '#' && s[i][j + 1] != '#')
          flag = false;
      }
      else if (j == W - 1)
      {
        if (s[i + 1][j] != '#' && s[i - 1][j] != '#' && s[i][j - 1] != '#')
          flag = false;
      }
      else if (s[i + 1][j] != '#' && s[i - 1][j] != '#' && s[i][j + 1] != '#' && s[i][j - 1] != '#')
        flag = false;
      if (!flag)
        break;
    }
  }
  if (flag)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}