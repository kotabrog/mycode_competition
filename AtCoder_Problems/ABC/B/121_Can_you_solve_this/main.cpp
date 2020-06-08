#include <bits/stdc++.h>
using namespace std;

int main()
{ 
  int n, m, c, a, sum_ab, ans = 0;
  vector<int> b(20);

  cin >> n >> m >> c;
  for (int i = 0; i < m; i++)
    cin >> b[i];
  for (int i = 0; i < n; i++)
  {
    sum_ab = c;
    for (int j = 0; j < m; j++)
    {
      cin >> a;
      sum_ab += a * b[j];
    }
    if (sum_ab > 0)
      ans++;
  }
  cout << ans << endl;
}