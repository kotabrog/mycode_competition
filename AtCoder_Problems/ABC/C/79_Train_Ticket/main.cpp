#include <bits/stdc++.h>
using namespace std;

int ctoi(char c)
{
  return (int)(c - '0');
}

int main()
{
  int A, B, C, D;
  string s;

  cin >> s;
  A = ctoi(s[0]);
  B = ctoi(s[1]);
  C = ctoi(s[2]);
  D = ctoi(s[3]);

  if (A + B + C + D == 7)
    cout << A << '+' << B << '+' << C << '+' << D << "=7" << endl;
  else if (A + B + C - D == 7)
    cout << A << '+' << B << '+' << C << '-' << D << "=7" << endl;
  else if (A + B - C + D == 7)
    cout << A << '+' << B << '-' << C << '+' << D << "=7" << endl;
  else if (A + B - C - D == 7)
    cout << A << '+' << B << '-' << C << '-' << D << "=7" << endl;
  else if (A - B + C + D == 7)
    cout << A << '-' << B << '+' << C << '+' << D << "=7" << endl;
  else if (A - B + C - D == 7)
    cout << A << '-' << B << '+' << C << '-' << D << "=7" << endl;
  else if (A - B - C + D == 7)
    cout << A << '-' << B << '-' << C << '+' << D << "=7" << endl;
  else if (A - B - C - D == 7)
    cout << A << '-' << B << '-' << C << '-' << D << "=7" << endl;
}