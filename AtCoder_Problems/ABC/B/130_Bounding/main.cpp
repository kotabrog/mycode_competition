#include <bits/stdc++.h>
using namespace std;

int main()
{ 
  int n, x, l, l_sum = 0, ans = 1;

  cin >> n >> x;
  for (int i = 0; i < n; i++)
  {
    cin >> l;
    l_sum += l;
    if (l_sum <= x)
      ans++;
  }
  cout << ans << endl;
}