#include <bits/stdc++.h>
using namespace std;

int main()
{
  map<string, int> s;
  int n, p, p_sum = 0;
  string t, top_s;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> t >> p;
    p_sum += p;
    s[t] = p;
    if (i == 0)
      top_s = t;
    else
    {
      if (s[top_s] < p)
        top_s = t;
    }
  }
  cout << (p_sum / 2 < s[top_s] ? top_s : "atcoder") << endl;
}
