#include <bits/stdc++.h>
using namespace std;

int main()
{
  int x, a, b;
  cin >> x >> a >> b;
  cout << (0 <= a - b ? "delicious" : b - a <= x ? "safe" : "dangerous") << endl;
}
