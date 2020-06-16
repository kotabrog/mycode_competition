#include <bits/stdc++.h>
using namespace std;

// 小数点以下桁数
// fixed << setprecision(i)

int gcd(int a,int b){return (a%b==0?b:gcd(b, a%b));}
int lcm(int a,int b){return a*b/gcd(a, b);}

int main()
{
  int sum_a;
  vector<int> seq;
  vector<int> abcde(5);

  for (int i = 0; i < 5; i++)
    cin >> abcde[i];
  for (int tmp = 0; tmp < (1 << 5); tmp++)
  {
    bitset<5> s(tmp);
    if (s.count() != 3)
      continue;
    sum_a = 0;
    for (int i = 0; i < 5; i++)
    {
      if (s[i])
        sum_a += abcde[i];
    }
    seq.push_back(sum_a);
  }
  sort(seq.begin(), seq.end());
  cout << seq[7] << endl;
}