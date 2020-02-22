#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<int> x(N);
  for (int i = 0; i < N; i++)
    cin >> x[i];
  sort(x.begin(), x.end());

  int count;
  int ans = 1000000000;
  for (int i = x[0]; i <= x[N - 1]; i++)
  {
    count = 0;
    for (int j = 0; j < N; j++)
      count += (x[j] - i) * (x[j] - i);
    if (count < ans)
      ans = count;
  }
  cout << ans << endl;
}