#include <bits/stdc++.h>
using namespace std;

int main()
{ 
  string s = "", t = "", x;
  char c;
  int sn, tn;

  cin >> x;
  s += x[0];
  s += x[1];
  t += x[2];
  t += x[3];
  sn = stoi(s);
  tn = stoi(t);
  cout << (sn <= 12 && sn != 0 && tn <= 12 && tn != 0? "AMBIGUOUS" : sn <= 12 && sn != 0 ? "MMYY" : tn <= 12 && tn != 0 ? "YYMM" : "NA") << endl;
}