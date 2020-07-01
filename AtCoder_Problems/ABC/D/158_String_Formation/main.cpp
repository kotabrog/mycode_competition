#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  int q, t, f;
  char c;
  int rev_flag = 1, a_count = 0, b_count = 0;
  vector<char> a(200000);
  vector<char> b(200000);

  cin >> s >> q;
  for (int i = 0; i < q; i++)
  {
    cin >> t;
    if (t == 1)
      rev_flag *= -1;
    else
    {
      cin >> f >> c;
    if ((f == 1 && rev_flag == 1) || (f != 1 && rev_flag != 1))
    {
      a[a_count] = c;
      a_count++;
    }
    else
    {
      b[b_count] = c;
      b_count++;
    }
    }
  }
  if (rev_flag == 1)
  {
    for (int i = 0; i < a_count; i++)
      cout << a[a_count - i - 1];
    cout << s;
    for (int i = 0; i < b_count; i++)
      cout << b[i];
  }
  else
  {
    for (int i = 0; i < b_count; i++)
      cout << b[b_count - i - 1];
    reverse(s.begin(), s.end());
    cout << s;
    for (int i = 0; i < a_count; i++)
      cout << a[i];
  }
  cout << endl;
}