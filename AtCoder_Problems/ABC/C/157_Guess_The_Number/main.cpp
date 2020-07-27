#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int gcd(int a,int b){return (a%b==0?b:gcd(b, a%b));}
int64_t lcm(int a,int b){return (int64_t)a*b/gcd(a, b);}
int factorial(int a){int b=1;while(a){b*=a--;}return b;} //13以下対応
bool is_prime(int a){if(a<=1)return false;for(int i=2;(int64_t)i*i<=a;i++){if(a%i==0)return false;}return true;}
int get_adp(double x, int n){return (int)round((x-(int)x)*pow(10,n))%10;} // 小数点以下の指定桁の値を取得

//順列の全列挙
// vector<int> v(N);
// iota(v.begin(), v.end(), 1);       // v に 1, 2, ... N を設定
// do {
//   for(auto x : v) cout << x << " "; cout << "\n";    // v の要素を表示
// } while( next_permutation(v.begin(), v.end()) ); 

//bit全探索
// for (int tmp = 0; tmp < (1 << ビット数); tmp++) {
//   bitset<ビット数> s(tmp);
//   // (ビット列sに対する処理)
// }

int main()
{
  int n, m, ans = -1, loop, start, temp_s, temp_c, temp, check;
  bool flag;
  vector<int> c(3, -1);

  cin >> n >> m;
  loop = pow(10, n);
  start = (n == 1 ? 0 : pow(10, n - 1));
  flag = true;
  for (int i = 0; i < m; i++)
  {
    cin >> temp_s >> temp_c;
    if (c[temp_s - 1] == -1 || c[temp_s - 1] == temp_c)
      c[temp_s - 1] = temp_c;
    else
      flag = false;
  }
  if (!flag)
  {
    cout << -1 << endl;
    return (0);
  }
  for (int i = start; i < loop; i++)
  {
    temp = i;
    check = 0;
    flag = true;
    if (n == 3)
    {
      if (c[check] != -1 && c[check] != temp / 100)
        flag = false;
      temp -= (temp / 100) * 100;
      check++;
    }
    if (n >= 2)
    {
      if (c[check] != -1 && c[check] != (temp / 10))
        flag = false;
      temp -= (temp / 10) * 10;
      check++;
    }
    if (c[check] != -1 && c[check] != temp)
      flag = false;
    if (flag)
    {
      cout << i << endl;
      return (0);
    }
  }
  cout << -1 << endl;
}