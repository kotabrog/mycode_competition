#include <bits/stdc++.h>
using namespace std;

int main()
{ 
  int n, ans = 10000, sum_w = 0, x = 0;
  vector<int> w(100);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> w[i];
    sum_w += w[i];
  }
  for (int i = 0; i < n - 1; i++)
  {
    x += w[i];
    ans = min(ans, abs(2 * x - sum_w));
  }
  cout << ans << endl;
}