#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, p, p_count = 0;
  vector<bool> a(100001, false);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> p;
    if (a[p])
      p_count++;
    else
      a[p] = true;
  }
  cout << p_count << endl;
}
