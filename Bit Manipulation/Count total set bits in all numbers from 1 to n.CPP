#include <bits/stdc++.h>
using namespace std;

//to find the power of 2 just before n
int leftmostbit(int n)
{
  int cnt = 0;
  while (n > 1)
  {
    n = n >> 1;
    cnt++;
  }
  return cnt;
}
//count set bits from 1 to n TC :O(LOGN)
int solve(int n)
{
  if (n == 0) return 0;
  int x = leftmostbit(n);
  //no of set bits in 0 to 2^x-1 (1<<(x-1))
  int bitsupto2raisetox = x * (1 << (x - 1));
  int msbfrom2raisexton = n - (1 << x) + 1;
  int remain = n - (1 << x);
  int ans = bitsupto2raisetox + msbfrom2raisexton + solve(remain);
  return ans;
}

int main() {
  int n; cin >> n;
  cout << solve(n);

}
