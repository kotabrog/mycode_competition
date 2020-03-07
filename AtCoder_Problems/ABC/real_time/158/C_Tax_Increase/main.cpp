#include <bits/stdc++.h>
using namespace std;

int main()
{
  int A, B, flag = -1;

  cin >> A >> B;
  for (int i = 0; i < 2000; i++)
  {
    if ((int)(i * 0.08) == A && (int)(i * 0.1) == B)
    {
      flag = i;
      break;
    }
    
  }
  cout << flag << endl;
}