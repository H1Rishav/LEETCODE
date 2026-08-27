#include<bits/stdc++.h>
using namespace std;
long long a[200005],seg[400020];

void build(int ind,int low,int high){
    if(low==high)
    {
        seg[ind]=1LL*a[low];
        return;
    }
    int mid=(low+high)/2;
    build(2*ind+1,low,mid);
    build(2*ind+2,mid+1,high);
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];

}
long long query(int ind,int low,int high,int l,int r){
    if(low>=l&&high<=r)
    return 1LL*seg[ind];
    if(high<l||low>r) return 0LL;

    int mid=(low+high)/2;
    long long left=query(2*ind+1,low,mid,l,r);
    long long right=query(2*ind+2,mid+1,high,l,r);
    return left+right;
}
void update(int ind,int low,int high,int up,int val)
{
    if(low==high)
    {
        seg[ind]=1LL*val;return;}

    int mid=(low+high)/2;
    if(mid>=up)
    update(2*ind+1,low,mid,up,val);
    else 
    update(2*ind+2,mid+1,high,up,val);

    seg[ind]=1LL*seg[2*ind+1]+1LL*seg[2*ind+2];
}
int main(){
    int n, q;
    cin>>n>>q;

    for(int i=0;i<n;i++)
    cin>>a[i];
    build(0,0,n-1);
    while(q--){
        int type,a,b;
        cin>>type>>a>>b;
        if(type==2)
        cout<<query(0,0,n-1,a-1,b-1)<<endl;
        else
        update(0,0,n-1,a-1,b);
    }
}