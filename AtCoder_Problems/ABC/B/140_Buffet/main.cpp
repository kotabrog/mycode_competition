#include <bits/stdc++.h>
using namespace std;

int main()
{ 
  int n, ans = 0;
  vector<vector<int>> abc(3, vector<int>(20));

  cin >> n;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i != 2 || j != n - 1)
        cin >> abc[i][j];
    }
  }
  for (int i = 0; i < n; i++)
  {
    ans += abc[1][abc[0][i] - 1];
    if (i != n - 1)
    {
      if (abc[0][i + 1] == abc[0][i] + 1)
        ans += abc[2][abc[0][i] - 1];
    }
  }
  cout << ans << endl;
}