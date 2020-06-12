#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  string s;

  cin >> n >> s;
  for (int i = 0; i < s.size(); i++)
    s[i] = (char)((((s[i] - 'A') + n) % 26) + 'A');
  cout << s << endl;
}