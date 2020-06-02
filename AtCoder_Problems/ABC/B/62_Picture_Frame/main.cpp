#include <bits/stdc++.h>
using namespace std;

int main()
{
  int h, w;
  vector<vector<char>> a(102, vector<char>(102, '#'));

  cin >> h >> w;
  for (int i = 1; i <= h; i++)
  {
    for (int j = 1; j <= w; j++)
      cin >> a[i][j];
  }
  for (int i = 0; i <= h + 1; i++)
  {
    for (int j = 0; j <= w + 1; j++)
      cout << a[i][j];
    cout << endl;
  }
}