#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<int> a(3 * N);
  for (int i = 0; i < 3 * N; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  
  int64_t ans = 0;
  for (int i = N; i < 3 * N; i += 2)
    ans += a[i];
  cout << ans << endl;
}
