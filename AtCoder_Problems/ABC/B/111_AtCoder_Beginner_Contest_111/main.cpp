#include <bits/stdc++.h>
using namespace std;

int main()
{ 
  int n;

  cin >> n;
  for (int i = 1; i <= 9; i++)
  {
    if (n <= 111 * i)
    {
      cout << 111 * i << endl;
      break;
    }
  }
}