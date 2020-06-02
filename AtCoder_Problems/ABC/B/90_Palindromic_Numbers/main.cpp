#include <bits/stdc++.h>
using namespace std;

int main()
{
  int A, B, temp;
  vector<int> i_digit(5);
  int count = 0;

  cin >> A >> B;
  for (int i = A; i <= B; i++)
  {
    temp = i;
    for (int j = 0; j < 5; j++)
    {
      i_digit[j] = temp % 10;
      temp /= 10;
    }
    if (i_digit[4] == i_digit[0] && i_digit[3] == i_digit[1])
      count++;
  }
  cout << count << endl;
}