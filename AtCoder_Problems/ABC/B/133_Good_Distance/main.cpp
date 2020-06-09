#include <bits/stdc++.h>
using namespace std;

int main()
{ 
  int n, d, ans = 0, sn, sqsn;
  vector<vector<int>> x(10, vector<int>(10));

  cin >> n >> d;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < d; j++)
      cin >> x[i][j];
  }
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      sn = 0;
      for (int k = 0; k < d; k++)
        sn += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
      sqsn = (int)sqrt(sn);
      if (sn == sqsn * sqsn)
        ans++;
    }
  }
  cout << ans << endl;
}