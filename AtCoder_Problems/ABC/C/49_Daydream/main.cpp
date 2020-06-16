#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<string> dr = {"dream", "erase"};
  string S;
  int start_n = 0;
  bool flag;
  int S_len;

  cin >> S;
  S_len = S.size();
  while (5 <= S_len - start_n)
  {
    if (!S.compare(start_n, 5, dr[0]))
    {
      start_n += 5;
      if (S_len - start_n < 2)
        continue;
      if (!S.compare(start_n, 2, "er"))
      {
        if (5 <= S_len - start_n)
        {
          if (!S.compare(start_n, 5, dr[1]))
            continue;
        }
        start_n += 2;
      }
    }
    else if (!S.compare(start_n, 5, dr[1]))
    {
      start_n += 5;
      if (S_len - start_n < 1)
        continue;
      if (!S.compare(start_n, 1, "r"))
        start_n += 1;
    }
    else
    {
      cout << "NO" <<endl;
      return (0);
    }
  }
  if (S_len == start_n)
    cout << "YES" <<endl;
  else
    cout << "NO" <<endl;
}