#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    unordered_map<int,int>mp;

    for(int i=0;i<n;i++){
         cin>>arr[i];
         
    }
    for(int i=0;i<k;i++)
    {
        if(arr[i]<k)
        mp[arr[i]]++;
    }
    set<vector<int>>st;
    int count=0;
    for(int i=0;i<k;i++)
    {
        st.insert(vector<int>{mp[i],i});
    }
    vector<int>ans;
    auto it=*st.begin();
    if(it[0]!=1)
    ans.push_back(it[1]);
    else
    ans.push_back(k);
    for(int i=k;i<n;i++){
        int num=arr[i-k];
        int curr=arr[i];
        
        if(num<k){
        auto it=st.upper_bound({mp[num],num-1});
        mp[num]--;
        if(it!=st.end())
        st.erase(it);
        st.insert({mp[num],num});
        }

        if(curr<k){
        auto it1=st.upper_bound({mp[curr],curr-1});
        mp[curr]++;
        if(it1!=st.end())
        st.erase(it1);
        st.insert({mp[curr],curr});
        }
        auto top=*st.begin();
        if(top[0]!=1)
        ans.push_back(top[1]);
        else
        ans.push_back(k);
        
        

    }
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    
    
    
}
int main(){
    int t=1;
    //cin>>t;
    while(t--) solve();
}