#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, a, b, k, p;
  vector<bool> v(101, false);
  string ans = "YES";
  
  cin >> n >> a >> b >> k;
  v[a] = true;
  v[b] = true;
  for (int i = 0; i < k; i++)
  {
    cin >> p;
    if (v[p])
      ans = "NO";
    else
      v[p] = true;
  }
  cout << ans << endl;
}
