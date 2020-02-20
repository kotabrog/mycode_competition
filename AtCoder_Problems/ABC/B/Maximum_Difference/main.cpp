#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, A;
  int max_A = 1;
  int min_A = 1000000000;

  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> A;
    if (max_A < A)
      max_A = A;
    if (A < min_A)
      min_A = A;
  }
  cout << max_A - min_A << endl;
}