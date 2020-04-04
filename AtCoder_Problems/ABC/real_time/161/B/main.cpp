#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, M, sum = 0, count = 0;
  vector<int> A(100);

  cin >> N >> M;
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
    sum += A[i];
  }
  for (int i = 0; i < N; i++)
  {
    if (sum <= A[i] * 4 * M)
      count++;
  }
  if (count < M)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
}