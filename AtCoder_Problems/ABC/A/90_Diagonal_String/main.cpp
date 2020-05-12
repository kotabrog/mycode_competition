#include <bits/stdc++.h>
using namespace std;

int main()
{
  char a;
  vector<char> x(3);
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cin >> a;
      if (i == j)
        x[i] = a;
    }
  }
  for (int i = 0; i < 3; i++)
    cout << x[i];
  cout << endl;
}