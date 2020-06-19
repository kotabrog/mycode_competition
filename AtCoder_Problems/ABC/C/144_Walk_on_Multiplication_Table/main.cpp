#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int gcd(int a,int b){return (a%b==0?b:gcd(b, a%b));}
int lcm(int a,int b){return a*b/gcd(a, b);}

int main()
{
  int64_t n, tmp;

  cin >> n;
  tmp = n - 1;
  for (int64_t i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
      tmp = i + n / i - 2;
  }
  cout << tmp << endl;
}