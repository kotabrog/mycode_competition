#include <bits/stdc++.h>
using namespace std;

int main()
{
  // max:31
  int x, ans = 1, tmp;
  
  cin >> x;
  for (int i = 2; i <= 31; i++)
  {
    tmp = i;
    while (tmp * i <= x)
      tmp *= i;
    if (tmp != i)
      ans = max(ans, tmp);
  }
  cout << ans << endl;
}