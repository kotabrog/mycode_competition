#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  vector<vector<char>> s(50, vector<char>(50));

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cin >> s[i][j];
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << s[n - 1 - j][i];
    }
    cout << endl;
  }
}
