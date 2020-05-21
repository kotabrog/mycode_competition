#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, ans=100, a;
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> a;
    ans = min(a, ans);
  }
  cout << ans << endl;
}
