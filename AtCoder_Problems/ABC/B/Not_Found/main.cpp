#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  int ans = 26;
  vector<int> v(26, 0);

  cin >> s;
  for (auto c: s)
    v[c - 'a']++;
  for (int i = 0; i < 26; i++)
  {
    if (!v[i])
    {
      ans = i;
      break;
    }
  }
  if (ans == 26)
    cout << "None" << endl;
  else
    cout << (char)(ans + 'a') << endl;
}