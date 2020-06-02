#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  string s;

  cin >> s;
  N = s.size();
  for (int i = 0; i < N; i++)
  {
    if (i % 2 == 0)
      cout << s.at(i);
  }
  cout << endl;
}