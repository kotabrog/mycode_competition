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

void check_s(vector<string> &sub_s, int& k, string s)
{
	for (int i = 0; i < k; i++)
		if (sub_s[i] == s)
			return ;
	for (int i = 0; i < k; i++)
	{
		if (s < sub_s[i])
		{
			for (int j = k - 2; j >= i; j--)
				sub_s[j + 1] = sub_s[j];
			sub_s[i] = s;
			break ;
		}
	}
}

int main()
{
	string s;
	int k, c;
	vector<string> sub_s(5, "zzzzz");

	cin >> s >> k;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 1; j <= k; j++)
		{
			string temp = s.substr(i, j);
			check_s(sub_s, k, temp);
		}
	}
	// for (int i = 0; i < k; i++)
	// 	cout << sub_s[i] << endl;
	
	cout << sub_s[k - 1] << endl;
}