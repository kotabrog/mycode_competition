#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int gcd(int a,int b){return (a%b==0?b:gcd(b, a%b));}
int lcm(int a,int b){return a*b/gcd(a, b);}

int main()
{
  int n, max_h = 0, flag = 0, h;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> h;
    flag = max(flag, max_h - h);
    max_h = max(max_h, h);
  }
  cout << (flag <= 1 ? "Yes" : "No") << endl;
}