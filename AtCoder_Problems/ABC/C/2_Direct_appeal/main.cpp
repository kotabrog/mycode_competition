#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int gcd(int a,int b){return (a%b==0?b:gcd(b, a%b));}
int lcm(int a,int b){return a*b/gcd(a, b);}

int main()
{
  int ax, ay, bx, by, cx, cy;

  cin >> ax >> ay >> bx >> by >> cx >> cy;
  ax -= cx;
  ay -= cy;
  bx -= cx;
  by -= cy;
  cout << fixed << setprecision(1) << (double)abs(ax * by - ay * bx) / 2 << endl;
}