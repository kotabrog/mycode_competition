#include <bits/stdc++.h>
using namespace std;

int main()
{ 
  int n, t, min_c = 1001;
  vector<vector<int>> ct(100, vector<int>(2));

  cin >> n >> t;
  for (int i = 0; i < n; i++)
  {
    cin >> ct[i][0] >> ct[i][1];
    if (ct[i][1] <= t && ct[i][0] < min_c)
      min_c = ct[i][0];
  }
  if (min_c == 1001)
    cout << "TLE" << endl;
  else
    cout << min_c << endl;
}