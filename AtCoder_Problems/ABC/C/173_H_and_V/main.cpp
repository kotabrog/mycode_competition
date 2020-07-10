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
  int h, w, k, count_b, ans = 0;
  char a;
  vector<vector<bool>> c(6, vector<bool>(6, false));

  cin >> h >> w >> k;
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      cin >> a;
      if (a == '#')
        c[i][j] = true;
    }
  }
  for (int tmp1 = 0; tmp1 < (1 << h); tmp1++)
  {
    bitset<6> s(tmp1);
    for (int tmp2 = 0; tmp2 < (1 << w); tmp2++)
    {
      count_b = 0;
      bitset<6> t(tmp2);
      for (int i = 0; i < h; i++)
      {
        for (int j = 0; j < w; j++)
        {
          if (s[i] && t[j])
          {
            if (c[i][j])
              count_b++;
          }
        }
      }
      if (count_b == k)
        ans++;
    }
  }
  cout << ans << endl;
}