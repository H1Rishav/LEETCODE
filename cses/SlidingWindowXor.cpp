#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    int x,a,b,c;
    cin>>x>>a>>b>>c;
    vector<int>arr;
    arr.push_back(x);
    for(int i=1;i<n;i++){

        x=(1LL*a*x+b)%c;
        //cout<<x<<" ";
        arr.push_back(x);
    }
    long long ans=0;
   // multiset<int>st;
   long long curr=0;
    for(int i=0;i<k;i++)
    curr=1LL*arr[i]||curr;
    ans=ans^curr;
    for(int i=k;i<n;i++)
    {
        curr^=arr[i-k];
        curr||=arr[i];
        ans^=curr;
    }
    cout<<ans<<endl;
    
}
int main(){
    int t=1;
    //cin>>t;
    while(t--) solve();
}