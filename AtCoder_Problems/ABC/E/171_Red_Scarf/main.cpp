#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int gcd(int a,int b){return (a%b==0?b:gcd(b, a%b));}
int lcm(int a,int b){return a*b/gcd(a, b);}

int main()
{
  int n, max_a, tmp;
  vector<bitset<30>> a(200000);
  vector<int> b(30, 0);
  
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> tmp;
    bitset<30> s(tmp);
    a[i] = s;
    for (int j = 0; j < 30; j++)
      b[j] += a[i][j];
  }
  for (int i = 0; i < n; i++)
  {
    bitset<30> s(0);
    for (int j = 0; j < 30; j++)
    {
      if (b[j] % 2 && !a[i][j])
        s[j] = 1;
      else if (!(b[j] % 2) && a[i][j])
        s[j] = 1;
    }
    cout << s.to_ullong() << endl;
  }
}