#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s, t, u;
  int a, b;
  cin >> s >> t >> a >> b >> u;
  cout << (s == u ? a - 1 : a) << " " << (s == u ? b : b - 1) << endl;
}