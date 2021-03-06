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

int main()
{
  int n;
  string s;
  vector<int> s_count(4, 0);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> s;
    if (s == "AC")
      s_count[0]++;
    else if (s == "WA")
      s_count[1]++;
    else if (s == "TLE")
      s_count[2]++;
    else if (s == "RE")
      s_count[3]++;
  }
  cout << "AC x " << s_count[0] << endl;
  cout << "WA x " << s_count[1] << endl;
  cout << "TLE x " << s_count[2] << endl;
  cout << "RE x " << s_count[3] << endl;
}