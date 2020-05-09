#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, count_5 = 0, count_7 = 0;
  for (int i = 0; i < 3; i++)
  {
    cin >> a;
    if (a == 5)
      count_5++;
    else if (a == 7)
      count_7++;
    else
      break;
  }
  cout << ((count_5 == 2 && count_7 == 1) ? "YES" : "NO") << endl;

}
