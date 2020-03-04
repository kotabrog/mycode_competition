#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, C, K;
  cin >> N >> C >> K;

  vector<int> T(N);
  for (int i = 0; i < N; i++)
    cin >> T[i];
  sort(T.begin(), T.end());

  int time = T[0], count = C, ans = 0;
  for (int i = 0; i < N; i++)
  {
    if (count == C || time + K < T[i])
    {
      count = 1;
      ans++;
      time = T[i];
      continue;
    }
    count++;
  }
  cout << ans << endl;
}
