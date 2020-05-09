#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, k, x, y;
  cin >> n >> k >> x >> y;
  cout << min(n, k) * x + (k < n ? (n - k) * y : 0) << endl;
}
