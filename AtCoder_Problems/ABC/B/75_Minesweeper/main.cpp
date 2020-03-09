#include <bits/stdc++.h>
using namespace std;

int main()
{
  int H, W;
  vector<vector<int>> a(50, vector<int>(50, 0));
  vector<string> s(50);

  cin >> H >> W;
  for (int i = 0; i < H; i++)
  {
    cin >> s[i];
    for (int j = 0; j < W; j++)
    {
      if (s[i][j] == '#')
      {
        if (i != 0)
        {
          if (j != 0)
            a[i - 1][j - 1]++;
          a[i - 1][j]++;
          if (j != W - 1)
            a[i - 1][j + 1]++;
        }
        if (j != 0)
          a[i][j - 1]++;
        if (j != W - 1)
          a[i][j + 1]++;
        if (i != H - 1)
        {
          if (j != 0)
            a[i + 1][j - 1]++;
          a[i + 1][j]++;
          if (j != W - 1)
            a[i + 1][j + 1]++;
        }
      }
    }
  }
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if (s[i][j] == '#')
        cout << '#';
      else
        cout << a[i][j];
    }
    cout << endl;
  }
}