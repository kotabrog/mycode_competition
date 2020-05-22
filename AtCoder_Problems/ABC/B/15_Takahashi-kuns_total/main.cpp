#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, a, a_count=0, a_sum=0;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    if (a)
    {
      a_count++;
      a_sum += a;
    }
  }
  cout << (a_sum - 1) / a_count + 1 << endl;
}
