#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int gcd(int a,int b){return (a%b==0?b:gcd(b, a%b));}
int lcm(int a,int b){return a*b/gcd(a, b);}

int main()
{
  int n, max1 = 0, max2 = 0;
  vector<int> a(200000);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    if (a[i] > max1)
    {
      max2 = max1;
      max1 = a[i];
    }
    else if (a[i] > max2)
      max2 = a[i];
  }
  for (int i = 0; i < n; i++)
    cout << (a[i] == max1 ? max2 : max1) << endl;
}