#include <bits/stdc++.h>
using namespace std;

int main()
{ 
  int n, max_p = 0, p, ans = 0;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> p;
    max_p = max(max_p, p);
    ans += p;
  }
  cout << ans - max_p / 2 << endl;
}