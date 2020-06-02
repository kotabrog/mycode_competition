#include <bits/stdc++.h>
using namespace std;

int main()
{
  string a, b;
  
  cin >> a >> b;
  if (a.size() < b.size())
    cout << "LESS" << endl;
  else if (b.size() < a.size())
    cout << "GREATER" << endl;
  else
  {
    if (a.compare(b) < 0)
      cout << "LESS" << endl;
    else if (a.compare(b) > 0)
      cout << "GREATER" << endl;
    else
      cout << "EQUAL" << endl;
  }
}