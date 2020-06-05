#include <bits/stdc++.h>
using namespace std;

int main()
{ 
  int n, m, k, a, ans = 0;
  vector<int> a_sum(31, 0);

  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    cin >> k;
    for (int j = 0; j < k; j++)
    {
      cin >> a;
      a_sum[a]++;
    }
  }
  for (int i = 1; i <= m; i++)
  {
    if (a_sum[i] == n)
      ans++;
  }
  cout << ans << endl;
}