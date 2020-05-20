#include <bits/stdc++.h>
using namespace std;

int main()
{
  string a, b;
  cin >> a >> b;
  bool flag = true;
  for (int i = 0; i < a.size(); i++)
  {
    if (a[i] != b[i])
    {
      flag = false;
      break;
    }
  }
  if (flag)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}