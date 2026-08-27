#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    int x,a,b,c;
    cin>>x>>a>>b>>c;
    vector<int>arr;
    arr.push_back(x);
    int freq[32];
    memset(freq,0,sizeof(freq));
    for(int i=1;i<n;i++){

        x=(1LL*a*x+b)%c;
        //cout<<x<<" ";
        arr.push_back(x);
    }
    for(int i=0;i<k;i++){
        int num=arr[i];
        for(int j=0;j<32;j++)
        {
            if((1<<j)&num)freq[j]++;
        }
    }
    int ans=0;
    for(int i=0;i<32;i++)
    {
        if(freq[i]) ans+=(1<<i);
    }
    //cout<<ans<<" ";
    for(int i=k;i<n;i++){
        //ans=0;
        int num=arr[i-k];
        for(int j=0;j<32;j++)
        {
            if((1<<j)&num){
                freq[j]--;
            }
        }
        num=arr[i];
        for(int j=0;j<32;j++)
        {
            if((1<<j)&num){
                freq[j]++;
            }
        }
        int curr=0;
        for(int j=0;j<32;j++)
        {
            if(freq[j]){
                curr+=(1<<j);
            }
        }
        //cout<<curr<<" ";
        ans=ans^curr;

    }
    cout<<ans<<endl;
    
}
int main(){
    int t=1;
    //cin>>t;
    while(t--) solve();
}