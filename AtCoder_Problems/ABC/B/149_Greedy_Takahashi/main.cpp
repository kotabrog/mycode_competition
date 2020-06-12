#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t a, b, k;
  cin >> a >> b >> k;
  cout << max(a - k, (int64_t)0) << ' ' << max(min(b, b - k + a), (int64_t)0) << endl;
}