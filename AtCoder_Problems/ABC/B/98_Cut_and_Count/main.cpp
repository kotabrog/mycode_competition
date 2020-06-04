#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, ans = 0;
  string s;

  cin >> n >> s;
  for (int i = 1; i < n; i++)
  {
    vector<bool> sp(26, false);
    int tmp = 0;
    for (int j = 0; j < i; j++)
      sp[s[j] - 'a'] = true;
    for (int j = 0; j < n - i; j++)
    {
      if (sp[s[n - j - 1] - 'a'])
      {
        sp[s[n - j - 1] - 'a'] = false;
        tmp++;
      }
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}