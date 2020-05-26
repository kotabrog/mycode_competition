#include <bits/stdc++.h>
using namespace std;

int main()
{
  int l, h, n;
  vector<int> a(50);

  cin >> l >> h >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
  {
    if (a[i] < l)
      cout << l - a[i] << endl;
    else if (a[i] <= h)
      cout << 0 << endl;
    else
      cout << -1 << endl;
  }
}
