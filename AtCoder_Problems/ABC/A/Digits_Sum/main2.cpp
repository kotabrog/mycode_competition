#include <bits/stdc++.h>
using namespace std;

// reference: hariro

int main() {
  int N; 
  int ans = 0;

  cin >> N;
  while (N > 0)
  {
    ans += N % 10;
    N /= 10;
  }
  if (ans == 1)
    ans = 10;
  cout << ans << endl;
}