#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  int q = 0;

  cin >> s;
  for (int i = 0; i < s.size(); i++)
    q += s[i] - '0';
  cout << (stoi(s) % q == 0 ? "Yes" : "No") << endl;
}