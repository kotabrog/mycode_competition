#include <bits/stdc++.h>
using namespace std;

int main()
{
  string a, b;
  int num;

  cin >> a >> b;
  num = stoi(a + b);
  cout << (num == (int)sqrt(num) * (int)sqrt(num) ? "Yes" : "No") << endl;
}