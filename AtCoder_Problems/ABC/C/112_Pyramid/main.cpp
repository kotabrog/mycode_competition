#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int64_t gcd(int64_t a,int64_t b){return (a%b==0?b:gcd(b, a%b));}
int64_t lcm(int64_t a,int64_t b){return a/gcd(a, b)*b;}
int factorial(int a){int b=1;while(a){b*=a--;}return b;} //13以下対応
bool is_prime(int64_t a){if(a<=1)return false;for(int64_t i=2;(int64_t)i*i<=a;i++){if(a%i==0)return false;}return true;}
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
	int n, max_h = 0, max_n;
	vector<vector<int>> xyh(100, vector<int>(3));
	vector<vector<bool>> visited(101, vector<bool>(101, false));
	vector<int> ans(3);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> xyh[i][0] >> xyh[i][1] >> xyh[i][2];
		if (max_h < xyh[i][2])
		{
			max_h = xyh[i][2];
			max_n = i;
		}
	}
	queue<pair<pair<int, int>, int>> q;
	visited[xyh[max_n][0]][xyh[max_n][1]] = true;
	q.push(make_pair(make_pair(xyh[max_n][0], xyh[max_n][1]), xyh[max_n][2]));
	while (!q.empty())
	{
		pair<int, int> temp = q.front().first;
		int temp_h = q.front().second;
		q.pop();
		bool flag = true;
		for (int i = 0; i < n; i++)
		{
			if (xyh[i][2] != max(temp_h - abs(temp.first - xyh[i][0]) - abs(temp.second - xyh[i][1]), 0))
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			ans[0] = temp.first;
			ans[1] = temp.second;
			ans[2] = temp_h;
			break;
		}
		if (0 <= temp.first - 1 && !visited[temp.first - 1][temp.second])
		{
			q.push(make_pair(make_pair(temp.first - 1, temp.second), temp_h + 1));
			visited[temp.first - 1][temp.second] = true;
		}
		if (0 <= temp.second - 1 && !visited[temp.first][temp.second - 1])
		{
			q.push(make_pair(make_pair(temp.first, temp.second - 1), temp_h + 1));
			visited[temp.first][temp.second - 1] = true;
		}
		if (temp.first + 1 <= 100 && !visited[temp.first + 1][temp.second])
		{
			q.push(make_pair(make_pair(temp.first + 1, temp.second), temp_h + 1));
			visited[temp.first + 1][temp.second] = true;
		}
		if (temp.second + 1 <= 100 && !visited[temp.first][temp.second + 1])
		{
			q.push(make_pair(make_pair(temp.first, temp.second + 1), temp_h + 1));
			visited[temp.first][temp.second + 1] = true;
		}
	}
	cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
}
