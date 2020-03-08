#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, A, odd_count = 0;

  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> A;
    if (A % 2 == 1)
      odd_count++;
  }
  if (odd_count % 2 == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}