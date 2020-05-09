#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, b, c, ans = 3;
  cin >> a >> b >> c;
  if (a == b)
    ans--;
  if (a == c || b == c)
    ans--;
  cout << ans << endl;
}
