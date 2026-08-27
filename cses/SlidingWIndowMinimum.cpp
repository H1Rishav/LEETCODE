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
    int ans=0;
    multiset<int>st;
    for(int i=0;i<k;i++)
    st.insert(arr[i]);
    ans^=*st.begin();
    for(int i=k;i<n;i++)
    {
        st.erase(st.find(arr[i-k]));
        st.insert(arr[i]);
        ans^=*st.begin();
    }
    cout<<ans<<endl;
    
}
int main(){
    int t=1;
    //cin>>t;
    while(t--) solve();
}