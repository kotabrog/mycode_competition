#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  vector<vector<char>> a(50, vector<char>(50)), b(50, vector<char>(50));
  bool flag;

  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cin >> a[i][j];
  }
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < m; j++)
      cin >> b[i][j];
  }
  for (int i1 = 0; i1 < n - m + 1; i1++)
  {
    for (int i2 = 0; i2 < n - m + 1; i2++)
    {
      flag = true;
      for (int j = 0; j < m; j++)
      {
        for (int k = 0; k < m; k++)
        {
          if (a[i1+j][i2+k] != b[j][k])
          {
            flag = false;
            break;
          }
        }
        if (!flag)
          break;
      }
      if (flag)
        break;
    }
    if (flag)
      break;
  }
  cout << (flag ? "Yes" : "No") << endl;
}