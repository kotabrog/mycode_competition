#include <bits/stdc++.h>
using namespace std;

int main()
{
  int W, H, N;
  cin >> W >> H >> N;

  vector<vector<bool>> c(W, vector<bool>(H, true));
  int x, y, a;
  for (int i = 0; i < N; i++)
  {
    cin >> x >> y >> a;
    if (a == 1)
    {
      for (int j = 0; j < x; j++)
      {
        for (int k = 0; k < H; k++)
          c[j][k] = false;
      }
    }
    else if (a == 2)
    {
      for (int j = x; j < W; j++)
      {
        for (int k = 0; k < H; k++)
          c[j][k] = false;
      }
    }
    else if (a == 3)
    {
      for (int j = 0; j < W; j++)
      {
        for (int k = 0; k < y; k++)
          c[j][k] = false;
      }
    }
    else if (a == 4)
    {
      for (int j = 0; j < W; j++)
      {
        for (int k = y; k < H; k++)
          c[j][k] = false;
      }
    }
  }
  int count = 0;
  for (int i = 0; i < W; i++)
  {
    for (int j = 0; j < H; j++)
    {
      if (c[i][j])
        count++;
    }
  }
  cout << count << endl;
}