#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n = 0;
  string s;
  vector<char> a(10);

  cin >> s;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == 'B')
    {
      if (n != 0)
        n--;
    }
    else
    {
      a[n] = s[i];
      n++;
    }
  }
  for (int i = 0; i < n; i++)
    cout << a[i];
  cout << endl;
}