#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, ans = 0;
  string s;

  cin >> n >> s;
  for (int i = 0; i < n - 2; i++)
  {
    if (s[i] == 'A')
    {
      if (s[i + 1] == 'B')
      {
        if (s[i + 2] == 'C')
          ans++;
      }
    }
  }
  cout << ans << endl;
}