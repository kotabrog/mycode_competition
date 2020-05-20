#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  bool flag = true;
  int count = -1;

  cin >> N;

  vector<int> v(N);
  
  for (int i = 0; i < N; i++)
    cin >> v[i];
  while (flag)
  {
    count++;
    for (int i = 0; i < N; i++)
    {
      if (v[i] % 2 != 0)
      {
        flag = false;
        break;
      }
      else
      {
        v[i] /= 2;
      }
    }
  }
  cout << count << endl;
}