#include <bits/stdc++.h>
using namespace std;

int main()
{ 
  int n;
  vector<string> w(100);
  bool flag = true;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> w[i];
    if (i == 0)
      continue;
    if (w[i - 1][w[i - 1].size() - 1] != w[i][0])
      flag = false;
    for (int j = 0; j < i; j++)
    {
      if (w[i] == w[j])
        flag = false;
    }
    if (!flag)
      break;
  }
  cout << (flag ? "Yes" : "No") << endl;
}