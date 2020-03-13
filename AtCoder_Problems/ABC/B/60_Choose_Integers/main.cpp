#include <bits/stdc++.h>
using namespace std;

int main()
{
  int A, B, C, r;

  cin >> A >> B >> C;
  r = A % B;
  for (int i = 0; i < B; i++)
  {
    if ((r * i) % B == C)
    {
      r = -1;
      break;
    }
  }
  if (r == -1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}