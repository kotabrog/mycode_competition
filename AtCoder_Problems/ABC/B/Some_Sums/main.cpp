#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, A, B;
  int sum, num;
  int some_sums = 0;

  cin >> N >> A >> B;
  for (int i = 1; i <=N; i++)
  {
    sum = 0;
    num = i;
    for (int k = 0; k < 5; k++)
    {
      sum += num % 10;
      num /= 10;
    }
    if (A <= sum && sum <= B)
      some_sums += i;
  }
  cout << some_sums << endl;
}