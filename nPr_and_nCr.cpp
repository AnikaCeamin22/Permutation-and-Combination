#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+2, mod = 1e9 + 7;
long long   C[102][102]={0};

int power(long long n, long long k)
 {
  int ans = 1 % mod; n %= mod; if (n < 0) n += mod;
  while (k) {
    if (k & 1) ans = (long long) ans * n % mod;
    n = (long long) n * n % mod;
    k >>= 1;
  }
  return ans;
}
int f[N], invf[N];
int nCr(int n, int r)
{
  if (n < r or n < 0) return 0;
  return 1LL * f[n] * invf[r] % mod * invf[n - r] % mod;
}
int nPr(int n, int r)
{
  if (n < r or n < 0) return 0;
  return 1LL * f[n] * invf[n - r] % mod;
}
void prec()
{
  f[0] = 1;
  for (int i = 1; i < N; i++) {
    f[i] = 1LL * i * f[i - 1] % mod;
  }
  invf[N - 1] = power(f[N - 1], mod - 2);
  for (int i = N - 2; i >= 0; i--) {
    invf[i] = 1LL * invf[i + 1] * (i + 1) % mod;
  }
}

void pascal()
{
    C[0][0]=1;
    for(int i=1; i<102; i++)
    {
        C[i][0]=1;
        //cout<<C[i][0]<<" ";
        for(int j=1; j<=i; j++)
        {
            C[i][j]=C[i-1][j]+C[i-1][j-1];
            //cout<<C[i][j]<<" ";
        }
        //cout<<endl;
    }
    //cout<<endl;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();

  cout << nCr(6, 2) << '\n';
  cout << nPr(6, 2) << '\n';
  return 0;
}
