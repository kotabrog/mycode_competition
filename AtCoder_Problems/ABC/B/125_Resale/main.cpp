#include <bits/stdc++.h>
using namespace std;

int main()
{ 
  int n, ans = 0, c;
  vector<int> v(20);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> v[i];
  for (int i = 0; i < n; i++)
  {
    cin >> c;
    if (c < v[i])
      ans += v[i] - c;
  }
  cout << ans << endl;
}