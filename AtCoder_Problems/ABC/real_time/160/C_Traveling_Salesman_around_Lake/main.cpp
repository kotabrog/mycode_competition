#include <bits/stdc++.h>
using namespace std;

int main()
{
  int K, N, ans = 1000000;
  vector<int> A(200000);

  cin >> K >> N;
  for (int i = 0; i < N; i++)
    cin >> A[i];
  for (int i = 0; i < N; i++)
  {
    if (i == N - 1)
      ans = min(ans, A[i] - A[0]);
    else
      ans = min(ans, K - (A[i + 1] - A[i]));
  }
  cout << ans << endl;
}