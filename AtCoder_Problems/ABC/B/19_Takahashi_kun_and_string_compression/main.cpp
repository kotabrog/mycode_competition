#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  int i = 0;
  int a_count;
  char a;

  cin >> s;
  while (i < s.size())
  {
    a = s[i];
    a_count = 0;
    while (s[i] == a)
    {
      a_count++;
      i++;
      if (i == s.size())
        break;
    }
    cout << a << a_count;
  }
  cout << endl;
}
