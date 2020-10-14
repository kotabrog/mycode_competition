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

vector<int> a(15);
vector<vector<pair<int, int>>> xy(15, vector<pair<int, int>>(15));

vector<int> vec_copy(vector<int> v, int n)
{
	vector<int> cv(n);
	for (int i = 0; i < n; i++)
		cv[i] = v[i];
	return (cv);
}

void func(int *ans, int score, int index, vector<int> flag, int n)
{
	if (*ans == n)
		return ;
	for (int i = index; i < n; i++)
	{
		if (flag[i] != -1)
			continue;
		vector<int> temp_v = vec_copy(flag, n);
		bool con_flag = false;
		queue<int> q;
		int temp_score = score + 1;
		q.push(i);
		temp_v[i] = 1;
		while (!q.empty())
		{
			int val = q.front();
			q.pop();
			for (int j = 0; j < a[val]; j++)
			{
				pair<int, int> temp = xy[val][j];
				if (temp_v[temp.first] != -1 && temp_v[temp.first] != temp.second)
				{
					con_flag = true;
					break;
				}
				if (temp_v[temp.first] == -1)
				{
					temp_v[temp.first] = temp.second;
					if (temp.second)
					{
						temp_score++;
						q.push(temp.first);
					}
				}
			}
		}
		if (con_flag)
			continue;
		// cout << temp_score << " " << i << endl;
		*ans = max(*ans, temp_score);
		func(ans, temp_score, index+1, temp_v, n);
	}
}

int main()
{
	int n, ans = 0, x, y;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		for (int j = 0; j < a[i]; j++)
		{
			cin >> x >> y;
			xy[i][j] = make_pair(x - 1, y);
		}
	}
	vector<int> flag(n, -1);
	func(&ans, 0, 0, flag, n);
	cout << ans << endl;
}
