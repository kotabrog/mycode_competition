#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int gcd(int a,int b){return (a%b==0?b:gcd(b, a%b));}
int lcm(int a,int b){return a*b/gcd(a, b);}

int main()
{
  char c;
  cin >> c;
  if ('A' <= c && c <= 'Z')
    cout << 'A' << endl;
  else
    cout << 'a' << endl;
}