#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int gcd(int a,int b){return (a%b==0?b:gcd(b, a%b));}
int lcm(int a,int b){return a*b/gcd(a, b);}

int main()
{
  int n;
  vector<int> d(100000);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> d[i];
  sort(d.begin(), d.begin() + n);
  cout << d[n/2] - d[n/2-1] << endl;
}