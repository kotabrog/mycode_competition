#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, ans = 100, sum = 0, tmp_sum;
  vector<int> t(4);

  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> t[i];
    sum += t[i];
  }
  for (int tmp = 1; tmp < (1 << N); tmp++)
  {
    bitset<4> s(tmp);
    tmp_sum = 0;
    for (int i = 0; i < N; i++)
    {
      if (s.test(i))
        tmp_sum += t[i];
    }
    ans = min(ans, max(tmp_sum, sum - tmp_sum));
  }
  cout << ans << endl;
}