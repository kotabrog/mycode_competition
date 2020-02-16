#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  int a;
  int flag = 0;

  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> a;
    if (a % 2 == 0)
    {
      if ((a % 3 != 0) && (a % 5 != 0))
        flag = 1;
    }
  }
  if (!flag)
    cout << "APPROVED" << endl;
  else
    cout << "DENIED" << endl;
}