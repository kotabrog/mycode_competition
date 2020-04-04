#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, K;

  cin >> N >> K;
  cout << min(N - (N / K) * K, abs(N - ((N / K) * K + K))) << endl;
}