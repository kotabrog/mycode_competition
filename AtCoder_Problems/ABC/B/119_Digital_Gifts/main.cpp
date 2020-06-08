#include <bits/stdc++.h>
using namespace std;

int main()
{ 
  int n;
  string u;
  double x, ans = 0;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> x >> u;
    if (u == "JPY")
      ans += x;
    else
      ans += x * 380000;
  }
  cout << ans << endl;
}