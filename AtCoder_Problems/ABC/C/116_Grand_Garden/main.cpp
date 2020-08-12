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
	int n, ans = 0, h_min, left;
	pair<int, int> temp_pair;

	cin >> n;
	vector<int> h(n);
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++)
		cin >> h[i];
	q.push(make_pair(0, n - 1));
	while (!q.empty())
	{
		temp_pair = q.front();
		q.pop();
		if (temp_pair.first == temp_pair.second)
		{
			ans += h[temp_pair.first];
			// cout << h[temp_pair.first] << endl;
			continue;
		}
		left = temp_pair.first;
		h_min = h[left];
		for (int i = left + 1; i <= temp_pair.second; i++)
			h_min = min(h_min, h[i]);
		ans += h_min;
		for (int i = left; i <= temp_pair.second; i++)
		{
			if (h[i] == h_min)
			{
				if (i != left)
					q.push(make_pair(left, i - 1));
				left = i + 1;
			}
			else if (i == temp_pair.second)
				q.push(make_pair(left, i));
			h[i] -= h_min;
		}
		// for (int i = temp_pair.first; i <= temp_pair.second; i++)
		// 	cout << h[i] << " ";
		// cout << endl;
	}
	cout << ans << endl;
}
