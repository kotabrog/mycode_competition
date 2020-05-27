#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, q, l, r, t;
  vector<int> a(100, 0);

  cin >> n >> q;
  for (int i = 0; i < q; i++)
  {
    cin >> l >> r >> t;
    for (int j = l - 1; j < r; j++)
      a[j] = t;
  }
  for (int i = 0; i < n; i++)
    cout << a[i] << endl;
}
