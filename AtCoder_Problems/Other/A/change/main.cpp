#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, count = 0, i = 0;
  vector<int> money = {500, 100, 50, 10, 5, 1};

  cin >> a;
  a = 1000 - a;
  while (i < 6)
  {
    if (a == 0)
      break;
    if (money[i] <= a)
    {
      count++;
      a -= money[i];
    }
    else
      i++;
  }
  cout << count << endl;
}