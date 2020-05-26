#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, ans = 0;
  vector<int> r(1000);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> r[i];
  sort(r.begin(), r.begin() + n);
  reverse(r.begin(), r.begin() + n);
  for (int i = 0; i < n; i++)
    ans += (i % 2 ? -1 : 1) * r[i] * r[i];
  cout << fixed << setprecision(15) << ans * M_PI << endl;
}
