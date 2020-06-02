#include <bits/stdc++.h>
using namespace std;

int sum_digit(int n)
{
  int sum_n = 0;

  while (n != 0)
  {
    sum_n += n % 10;
    n /= 10;
  }
  return (sum_n);
}

int main()
{
  int N;
  string s = "No";

  cin >> N;
  if (N % sum_digit(N) == 0)
    s = "Yes";
  cout << s << endl;
}