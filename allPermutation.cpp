#include<bits/stdc++.h>
using namespace std;

using ll = long long int;
#define en  "\n"

void allPermutation(int indx, vector<int>&v)
{
    if(indx==v.size())
    {
        for(auto i : v) cout<<i<<" ";
        cout<<endl;
        return;
    }

    for(int i=indx; i<(int)v.size(); i++)
    {
        swap(v[indx],v[i]);
        allPermutation(indx+1,v);
        swap(v[indx],v[i]);
    }
}

void Solve()
{
   int n;
   cin>>n;
   vector<int>v(n);
   for(int i=0; i<n; i++) cin>>v[i];

   allPermutation(0,v);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int T=1,t=0;
    cin>>T;
    while(T--){
            t++;
   // cout<<"Case "<<t<<": ";
        Solve();
    }

    return 0;
}
