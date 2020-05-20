#include <bits/stdc++.h>
using namespace std;

int main()
{
  int A, B, C, X;
  int count = 0;

  cin >> A >> B >> C >> X;
  for (int i = 0; i <= A; i++)
  {
    if (X < (i * 500))
      break;
    else if (X == (i * 500))
    {
      count++;
      break;
    }
    for (int j = 0; j <= B; j++)
    {
      if (X < (i * 500 + j * 100))
        break;
      else if (X == (i * 500 + j * 100))
      {
        count++;
        break;
      }
      for (int k = 0; k <= C; k++)
      {
        if (X < (i * 500 + j * 100 + k * 50))
          break;
        else if (X == (i * 500 + j * 100 + k * 50))
        {
          count++;
          break;
        }
      }
    }
  }
  cout << count << endl;
}