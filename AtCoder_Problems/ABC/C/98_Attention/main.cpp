#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, ans;
  string s;
  vector<int> sum_WtoE(300000), sum_EtoW(300000);

  cin >> N >> s;
  if (s[0] == 'W')
    sum_WtoE[0] = 1;
  else
    sum_WtoE[0] = 0;
  if (s[N - 1] == 'E')
    sum_EtoW[0] = 1;
  else
    sum_EtoW[0] = 0;
  for (int i = 1; i < N - 1; i++)
  {
    if (s[i] == 'W')
      sum_WtoE[i] = sum_WtoE[i - 1] + 1;
    else
      sum_WtoE[i] = sum_WtoE[i - 1];
    if (s[N - 1 - i] == 'E')
      sum_EtoW[i] = sum_EtoW[i - 1] + 1;
    else
      sum_EtoW[i] = sum_EtoW[i - 1];
  }
  ans = sum_EtoW[N - 2];
  for (int i = 0; i < N - 2; i++)
    ans = min(ans, sum_WtoE[i] + sum_EtoW[N - 3 - i]);
  ans = min(ans, sum_WtoE[N - 2]);
  cout << ans << endl;
}