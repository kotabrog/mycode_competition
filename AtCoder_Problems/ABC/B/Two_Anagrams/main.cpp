#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s, t;
  cin >> s >> t;

  int s_size = s.size();
  int t_size = t.size();

  vector<char> s_array(s_size);
  vector<char> t_array(t_size);
  for (int i = 0; i < s_size; i++)
    s_array[i] = s[i];
  for (int i = 0; i < t_size; i++)
    t_array[i] = t[i];
  sort(s_array.begin(), s_array.end());
  sort(t_array.begin(), t_array.end());
  reverse(t_array.begin(), t_array.end());

  int N = min(s_size, t_size);
  string a = "No";
  int i = 0;

  while (i < N)
  {
    if (s_array[i] < t_array[i])
    {
      a = "Yes";
      break;
    }
    else if(t_array[i] < s_array[i])
    {
      a = "No";
      break;
    }
    i++;
  }
  if (i == N && s_size < t_size)
    a = "Yes";
  cout << a << endl;
}