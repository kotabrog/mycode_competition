#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<vector<int>> c(3, vector<int>(3));
  string ans = "Yes";

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
      cin >> c[i][j] ;
  }
  for (int i = 1; i < 3; i++)
  {
    if (c[0][0] - c[i][0] != c[0][1] - c[i][1] ||
        c[0][0] - c[i][0] != c[0][2] - c[i][2] ||
        c[0][0] - c[0][i] != c[1][0] - c[1][i] ||
        c[0][0] - c[0][i] != c[2][0] - c[2][i])
      ans = "No";
  }
  cout << ans << endl;
}