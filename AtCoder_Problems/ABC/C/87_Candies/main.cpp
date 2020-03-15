#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, ans = 0;
  vector<int> a(100);
  vector<int> b(100);
  vector<int> sum_a(100);
  vector<int> sum_b(100);

  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> a[i];
  for (int i = 0; i < N; i++)
    cin >> b[i];
  sum_a[0] = a[0];
  sum_b[0] = b[N - 1];
  for (int i = 1; i < N; i++)
  {
    sum_a[i] = sum_a[i - 1] + a[i];
    sum_b[i] = sum_b[i - 1] + b[N - 1 - i];
  }
  for (int i = 0; i < N; i++)
    ans = max(ans, sum_a[i] + sum_b[N - 1 - i]);
  cout << ans << endl;
}