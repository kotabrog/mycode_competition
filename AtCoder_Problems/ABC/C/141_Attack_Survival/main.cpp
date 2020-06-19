#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int gcd(int a,int b){return (a%b==0?b:gcd(b, a%b));}
int lcm(int a,int b){return a*b/gcd(a, b);}

int main()
{
  int n, k, q, a;
  vector<int> p(100000, 0);

  cin >> n >> k >> q;
  for (int i = 0; i < q; i++)
  {
    cin >> a;
    p[a - 1]++;
  }
  for (int i = 0; i < n; i++)
      cout << (k <= q - p[i] ? "No" : "Yes") << endl;
}