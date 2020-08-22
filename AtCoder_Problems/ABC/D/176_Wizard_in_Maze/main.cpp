#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int64_t gcd(int64_t a,int64_t b){return (a%b==0?b:gcd(b, a%b));}
int64_t lcm(int a,int b){return (int64_t)a*b/gcd(a, b);}
int factorial(int a){int b=1;while(a){b*=a--;}return b;} //13以下対応
bool is_prime(int a){if(a<=1)return false;for(int i=2;(int64_t)i*i<=a;i++){if(a%i==0)return false;}return true;}
int get_adp(double x, int n){return (int)round((x-(int)x)*pow(10,n))%10;} // 小数点以下の指定桁の値を取得
int64_t sigma(int64_t s, int64_t n){return n*(2*s+n-1)/2;}

//順列の全列挙
// vector<int> v(N);
// iota(v.begin(), v.end(), 1);       // v に 1, 2, ... N を設定
// do {
//	for(auto x : v) cout << x << " "; cout << "\n";     // v の要素を表示
// } while( next_permutation(v.begin(), v.end()) ); 

//bit全探索
// for (int tmp = 0; tmp < (1 << ビット数); tmp++) {
//	bitset<ビット数> s(tmp);
//	// (ビット列sに対する処理)
// }

int main()
{
  int h, w, temp1, temp2;
  pair<int, int> c, d;

  cin >> h >> w;
  cin >> temp1 >> temp2;
  c = make_pair(temp1 + 1, temp2 + 1);
  cin >> temp1 >> temp2;
  d = make_pair(temp1 + 1, temp2 + 1);

  vector<vector<char>> s(h + 4, vector<char>(w + 4, '#'));
  vector<vector<int>> flag(h + 4, vector<int>(w + 4, -1));

  for (int i = 2; i < 2 + h; i++)
  {
    for (int j = 2; j < 2 + w; j++)
    {
      cin >> s[i][j];
    }
  }

  flag[c.first][c.second] = 0;
  queue<pair<pair<int, int>, int>> q;
  q.push(make_pair(c, 0));
  while (!q.empty())
  {

    queue<pair<pair<int, int>, int>> p;
    p.push(q.front());

    while (!p.empty())
    {
      pair<int,int> tmp = p.front().first;
      int c_temp = p.front().second;
      p.pop();


      if (s[tmp.first - 1][tmp.second] == '.')
        if (flag[tmp.first - 1][tmp.second] == -1 || flag[tmp.first - 1][tmp.second] > c_temp)
        {
          p.push(make_pair(make_pair(tmp.first - 1, tmp.second), c_temp));
          q.push(make_pair(make_pair(tmp.first - 1, tmp.second), c_temp));
          flag[tmp.first - 1][tmp.second] = c_temp;
        }
      if (s[tmp.first + 1][tmp.second] == '.')
        if (flag[tmp.first + 1][tmp.second] == -1 || flag[tmp.first + 1][tmp.second] > c_temp)
        {
          p.push(make_pair(make_pair(tmp.first + 1, tmp.second), c_temp));
          q.push(make_pair(make_pair(tmp.first + 1, tmp.second), c_temp));
          flag[tmp.first + 1][tmp.second] = c_temp;
        }
      if (s[tmp.first][tmp.second - 1] == '.')
        if (flag[tmp.first][tmp.second - 1] == -1 || flag[tmp.first][tmp.second - 1] > c_temp)
        {
          p.push(make_pair(make_pair(tmp.first, tmp.second - 1), c_temp));
          q.push(make_pair(make_pair(tmp.first, tmp.second - 1), c_temp));
          flag[tmp.first][tmp.second - 1] = c_temp;
        }
      if (s[tmp.first][tmp.second + 1] == '.')
        if (flag[tmp.first][tmp.second + 1] == -1 || flag[tmp.first][tmp.second + 1] > c_temp)
        {
          p.push(make_pair(make_pair(tmp.first, tmp.second + 1), c_temp));
          q.push(make_pair(make_pair(tmp.first, tmp.second + 1), c_temp));
          flag[tmp.first][tmp.second + 1] = c_temp;
        }
    }
      // cout << (s[tmp.first - 1][tmp.second] == '.') << endl;
      // cout << tmp.first << " " << tmp.second << " " << q.size() << endl;

    pair<int,int> tmp = q.front().first;
    int c_temp = q.front().second;
    q.pop();



    for (int i = -2; i < 3; i++)
    {
      for (int j = -2; j < 3; j++)
      {
        if (s[tmp.first + i][tmp.second + j] == '.')
          if (flag[tmp.first + i][tmp.second + j] == -1 || flag[tmp.first + i][tmp.second + j] > c_temp + 1)
          {
            q.push(make_pair(make_pair(tmp.first + i, tmp.second + j), c_temp + 1));
            flag[tmp.first + i][tmp.second + j] = c_temp + 1;
          }
      }
    }
    // cout << "ok" << endl;
  }
  cout << flag[d.first][d.second] << endl;
}
