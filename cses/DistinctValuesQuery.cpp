#include<bits/stdc++.h>
using namespace std;
vector<int>seg;
void update(int ind,int low,int high,int nind,int val){
    if(low==high)
    {
        seg[ind]=val;return;}
    int mid=(low+high)/2;
    if(nind<=mid)
    update(2*ind+1,low,mid,nind,val);
    else
    update(2*ind+2,mid+1,high,nind,val);

    seg[ind]=seg[2*ind+1]+seg[2*ind+2];

}
int query(int ind,int low,int high,int l,int r)
{
    if(high<l||low>r)return 0;
    if(low>=l&&high<=r) return seg[ind];
    int mid=(low+high)/2;
    int ll=0,rr=0;
    ll=query(2*ind+1,low,mid,l,r);
    rr=query(2*ind+2,mid+1,high,l,r);
    return ll+rr;

}
void activate(int ind,int &track,vector<vector<int>>&trackv,int n){
    if(ind<0)return;
    if(ind<=track)return;
    for(int i=track+1;i<=ind;i++)
    {
        for(auto it:trackv[i]){
            update(0,0,n-1,it,1);
        }
        
    }
    track=ind;
}
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int>x(n);

    for(int i=0;i<n;i++)
    cin>>x[i];

    seg.assign(4*n,0);

    vector<int>prev(n);

    map<int,int>mp;

    vector<vector<int>>trackv(n);

    for(int i=0;i<n;i++)
    {
        int col=x[i];
        if(mp.find(col)==mp.end())
        {
            prev[i]=-1;
            update(0,0,n-1,i,1);
        }
        
        else
        {
            prev[i]=mp[col];
            trackv[mp[col]].push_back(i);
        }
        //cout<<i<<" "<<prev[i]<<endl;
        mp[col]=i;
    }
    //previous when it was seen is built
    int z=0;
    vector<vector<int>>queries;
    
    while(z<q){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        queries.push_back({a,b,z});z++;
    }
    sort(queries.begin(),queries.end());
    vector<int>ans(q);
    z=0;
    int track=-1;
    while(z<q){
        int curra=queries[z][0];
        int currb=queries[z][1];
        int ind=queries[z][2];

       activate(curra-1,track,trackv,n);
        ans[ind]=query(0,0,n-1,curra,currb);
        //cout<<curra<<" "<<currb<<" "<<ans[ind]<<endl;
        z++;

    }
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--)solve();
}