#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int gcd(int a,int b){return (a%b==0?b:gcd(b, a%b));}
int lcm(int a,int b){return a*b/gcd(a, b);}

int main()
{
  string s;
  int64_t k;
  
  cin >> s >> k;
  for (int i = 0; i < min((int64_t)s.size(), k); i++)
  {
    if (s[i] != '1')
    {
      cout << s[i] << endl;
      return 0;
    }
  }
  cout << 1 << endl;
}