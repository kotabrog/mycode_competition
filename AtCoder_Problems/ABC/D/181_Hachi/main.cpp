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
	string s;
	vector<int> num(10, 0);
	bool flag = false;

	cin >> s;
	for (int i = 0; i < s.size(); i++)
		num[s[i] - '0']++;
	for (int i = 8; i < 1000; i+=8)
	{
		vector<int> temp(10, 0);
		bool temp_flag = true;
		temp[i % 10]++;
		if (s.size() > 1)
			temp[(i / 10) % 10]++;
		if (s.size() > 2)
			temp[i / 100]++;
		for (int j = 0; j < 10; j++)
			if (num[j] < temp[j])
				temp_flag = false;
		if (temp_flag)
		{
			flag = true;
			break;
		}
	}
	cout << (flag ? "Yes" : "No") << endl;
}
