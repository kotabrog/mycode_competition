#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, A, B, r, ans;

  cin >> N >> A >> B;
  r = N % (A + B);
  ans = (N / (A + B) * A) + min(A, r);
  cout << ans << endl;
}