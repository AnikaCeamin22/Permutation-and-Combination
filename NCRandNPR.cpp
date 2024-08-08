#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define db long double


const ll N = 3e5 + 5;
const ll mod =  1e9 + 7;
const ll inf = 1e18;

ll bigmod(ll a, ll b) {
    if(b == 0) return 1ll;
    if(b & 1)  return (1ll * a * bigmod(a, b - 1)) % mod;
    ll ret = bigmod(a, b / 2);
    return (1ll * ret * ret) % mod;
}

ll fact[N], i_fact[N];

void factorial() {
    fact[0] = 1;
    for(int i = 1; i < N; i++)
        fact[i] = (1ll * fact[i - 1] * i) % mod;

    i_fact[N - 1] = bigmod(fact[N - 1], mod - 2);
    for(int i = N - 2; i >= 0; i--)
        i_fact[i] = (1ll * i_fact[i + 1] * (i + 1)) % mod;
}

ll ncr(ll n, ll r) {
    if(r > n)  return 0;
    return (1ll * fact[n] * (1ll * i_fact[r] * i_fact[n - r] % mod)) % mod;
}

ll npr(ll n, ll r) {
    return (1ll * fact[n] * i_fact[n - r]) % mod;
}

void Solve()
{
    ll n,k,ones=0,zeros=0;
    cin>>n>>k;
    for(int i=0; i<n; i++)
    {
       int x;
       cin>>x;
       ones+=x;
    }
    zeros=n-ones;   //cout<<ones<<  " =  "<<zeros<<endl;
    ll sum=0, one = k/2+1;
    while(one <=k && one<=ones)
    {
        //int zero=k-one;
        sum=(sum+(ncr(ones,one)*ncr(zeros,k-one))%mod)%mod;
        one++;
    }
    cout<<sum<<endl;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    factorial();

    int T=1,t=0;
    cin>>T;
    while(T--){
            t++;
   // cout<<"Case "<<t<<": ";
        Solve();
    }

    return 0;
}
