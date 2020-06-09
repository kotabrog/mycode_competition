#include <bits/stdc++.h>
using namespace std;

int main()
{ 
  string s;
  int ans = 0, tmp = 0;

  cin >> s;
  for (int i = 0; i < s.size(); i++)
  {
    if (string("ACGT").find(s[i]) != std::string::npos)
      tmp++;
    else
    {
      ans = max(ans, tmp);
      tmp = 0;
    }
  }
  ans = max(tmp, ans);
  cout << ans << endl;
}