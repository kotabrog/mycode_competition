#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  cout << (2 * max(a, max(b, c)) == (a + b + c) ? "Yes" : "No") << endl;
}
