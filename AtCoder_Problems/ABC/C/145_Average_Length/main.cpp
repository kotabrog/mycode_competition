#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int gcd(int a,int b){return (a%b==0?b:gcd(b, a%b));}
int lcm(int a,int b){return a*b/gcd(a, b);}
int factorial(int a){int b=1;while(a){b*=a--;}return b;} //13以下対応

double len_xy(int x1, int x2, int y1, int y2)
{
  return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main()
{
  int n, x, y;
  vector<pair<int, int>> xy(8);
  double ans = 0;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> x >> y;
    xy[i] = make_pair(x, y);
  }
  for (int i = 0; i < n - 1; i ++)
  {
    for (int j = i + 1; j < n; j++)
      ans += len_xy(xy[i].first, xy[j].first, xy[i].second, xy[j].second);
  }
  ans = ans * 2 / n;
  cout << fixed << setprecision(7) << ans << endl;
}