#include <bits/stdc++.h>
using namespace std;

int main()
{
  int A, B, C, D, ans;

  cin >> A >> B >> C >> D;
  ans = min(B, D) - max(A, C);
  cout << max(0, ans) << endl;
}