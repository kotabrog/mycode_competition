#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, M;
  string s = "No";

  cin >> N;
  M = N / 7;
  for (int i = 0; i <= M; i++)
  {
    if ((N - i * 7) % 4 == 0)
    {
      s = "Yes";
      break;
    }
  }
  cout << s << endl;
}