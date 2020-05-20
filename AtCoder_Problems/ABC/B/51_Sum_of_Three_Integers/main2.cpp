#include <bits/stdc++.h>
using namespace std;

int main()
{
  int K, S;
  int count = 0;

  cin >> K >> S;
  for (int i = max(S - 2 * K, 0); i <= K; i++)
  {
    if (S < i)
      break;
    if (S - i <= 2 * K)
        count += K - abs(S - i - K) + 1;
  }
  cout << count << endl;
}