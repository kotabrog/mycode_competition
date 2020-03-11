#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, K;

  cin >> N >> K;
  cout << (int64_t)(K * pow(K - 1, N - 1))<< endl;
}