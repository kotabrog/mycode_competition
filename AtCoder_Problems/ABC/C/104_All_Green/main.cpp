#include <bits/stdc++.h>
using namespace std;

//TLE

void all_green(vector<vector<int>> a, int G, int D, int *ans, int count, int sum)
{
  for (int i = 0; i < D; i++)
  {
    if (a[i][3])
      continue;
    a[i][3] = 1;
    if (sum + a[i][2] < G)
      all_green(a, G, D, ans, count + a[i][0], sum + a[i][2]);
    else
      *ans = min(*ans, min(count + (G - sum - 1) / ((i + 1) * 100) + 1, count + a[i][0]));
    a[i][3] = 0;
  }
}

int main()
{
  int D, G, ans = 10000;
  vector<vector<int>> a(10, vector<int>(4, 0));

  cin >> D >> G;
  for (int i = 0; i < D; i++)
  {
    cin >> a[i][0] >> a[i][1];
    a[i][2] = a[i][0] * 100 * (i + 1) + a[i][1];
  }
  all_green(a, G, D, &ans, 0, 0);
  cout << ans << endl;
}