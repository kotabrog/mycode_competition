#include <bits/stdc++.h>
using namespace std;

int main()
{ 
  int n, ans = 0;
  vector<int> p(20);
  vector<bool> flag(20);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> p[i];
  if (p[0] < p[1])
    flag[0] = true;
  else
    flag[0] = false;
  for (int i = 1; i < n - 1; i++)
  {
    if (p[i] < p[i + 1])
      flag[i] = true;
    else
      flag[i] = false;
    if (flag[i] == flag[i - 1])
      ans++;
  }
  cout << ans << endl;
}