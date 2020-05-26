#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  vector<int> a(6, 0);

  cin >> s;
  for (int i = 0; i < s.size(); i++)
    a[s[i] - 'A']++;
  for (int i = 0; i < 6; i++)
  {
    if (i == 5)
      cout << a[i] << endl;
    else
      cout << a[i] << ' ';
  }
}
