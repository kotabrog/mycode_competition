#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, b, c, n, N;
  cin >> a >> b >> c;
  n = min(a, min(b, c));
  N = max(a, max(b, c));
  cout << ((a == n && b == N) || (a == N && b == n) ? c : \
           (a == n && c == N) || (a == N && c == n) ? b : a) << endl;
}
