#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, t, a, b, time;

  cin >> n >> t >> a;
  time = t;
  for (int i = 0; i < n - 1; i++)
  {
    cin >> b;
    time += min(t, b - a);
    a = b;
  }
  cout << time << endl;
}
