#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, b;
  vector<vector<int>> a(3, vector<int>(3));
  vector<vector<bool>> flag(3, vector<bool>(3, false));

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
      cin >> a[i][j];
  }
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> b;
    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        if (b == a[i][j])
          flag[i][j] = true;
      }
    }
  }
  cout << ((flag[0][0] && flag[0][1] && flag[0][2]) ||\
          (flag[1][0] && flag[1][1] && flag[1][2]) ||\
          (flag[2][0] && flag[2][1] && flag[2][2]) ||\
          (flag[0][0] && flag[1][0] && flag[2][0]) ||\
          (flag[0][1] && flag[1][1] && flag[2][1]) ||\
          (flag[0][2] && flag[1][2] && flag[2][2]) ||\
          (flag[0][0] && flag[1][1] && flag[2][2]) ||\
          (flag[2][0] && flag[1][1] && flag[0][2]) ? "Yes" : "No") << endl;
}