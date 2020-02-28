#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> v(200001, 200001);
  int count = 0, ans = 0;
  int N, K, a;

  cin >> N >> K;
  for (int i = 0; i < N; i++)
  {
    cin >> a;
    if (v[a] == 200001)
    {
      count++;
      v[a] = 1;
    }
    else
      v[a]++;
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < count - K; i++)
    ans += v[i];
  cout << ans << endl;
}