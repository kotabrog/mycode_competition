#include <bits/stdc++.h>
using namespace std;

int main()
{
  int h, w;
  vector<vector<char>> c(100, vector<char>(100));

  cin >> h >> w;
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
      cin >> c[i][j];
  }
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
      cout << c[i][j];
    cout << endl;
    for (int j = 0; j < w; j++)
      cout << c[i][j];
    cout << endl;
  }
}