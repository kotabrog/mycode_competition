#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, j, count;
  int max_n = 1;
  int max_count = 0;

  cin >> N;
  for (int i = 1; i <= N; i++)
  {
    j = i;
    count = 0;
    while (j % 2 == 0)
    {
      j /= 2;
      count++;
    }
    if (max_count < count)
    {
      max_count = count;
      max_n = i;
    }
  }
  cout << max_n << endl;
}