// Problem: A. Profitable Interest Rate
// Contest: Codeforces - Codeforces Round 980 (Div. 2)
// URL: https://codeforces.com/contest/2024/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    long long a, b, c;
    cin >> a >> b;
    if (a < b)
    {
      c = 2 * a - b;
      if (c > 0)
        cout << c << endl;
      else
        cout << c * 0 << endl;
    }
    else
      cout << a << endl;
  }
}