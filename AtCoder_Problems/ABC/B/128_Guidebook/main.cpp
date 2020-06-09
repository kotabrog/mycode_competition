#include <bits/stdc++.h>
using namespace std;

bool f_comp(pair<string, pair<int, int>> p1, pair<string, pair<int, int>> p2)
{
  if (p1.first < p2.first)
    return (true);
  else if(p1.first > p2.first)
    return (false);
  else
  {
    if (p1.second.first > p2.second.first)
      return (true);
    else
      return (false);
  }
  
}

int main()
{ 
  string s;
  int p, n;
  
  cin >> n;
  vector<pair<string, pair<int, int>>> sp(n);
  for (int i = 0; i < n; i++)
  {
    cin >> s >> p;
    sp[i] = make_pair(s, make_pair(p, i + 1));
  }
  sort(sp.begin(), sp.end(), f_comp);
  for (int i = 0; i < n; i++)
    cout << sp[i].second.second << endl;
}