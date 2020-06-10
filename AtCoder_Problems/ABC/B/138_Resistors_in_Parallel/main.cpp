#include <bits/stdc++.h>
using namespace std;

int main()
{ 
  double ans = 0, a;
  int n;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    ans += 1 / a;
  }
  cout << fixed << setprecision(5) << 1 / ans << endl;
}