#include <bits/stdc++.h>
using namespace std;

// reference: pampam

int main()
{
  int N;
  int x = 2;

  cin >> N;
  while (x <= N)
  {
    x *= 2;
  }
  cout << x / 2 << endl;
}
