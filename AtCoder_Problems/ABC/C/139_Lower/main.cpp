#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int gcd(int a,int b){return (a%b==0?b:gcd(b, a%b));}
int lcm(int a,int b){return a*b/gcd(a, b);}

int main()
{
  int n, ans = 0, tmp = 0;
  vector<int> h(100000);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> h[i];
  for (int i = 1; i < n; i++)
  {
    if (h[i - 1] >= h[i])
      tmp++;
    else
    {
      ans = max(ans, tmp);
      tmp = 0;
    }
  }
  cout << max(ans, tmp) << endl;
}