#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<vector<int>>&adj,set<int>&st){
    
    st.insert(node);
    for(auto it:adj[node])
    {
        if(st.find(it)!=st.end()) continue;
        dfs(it,adj,st);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    //strongly connected components logic
    vector<vector<int>>adj(n),rev(n);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }

    //if a node is reachable upon reversing as well then fully connected
    set<int>st,st1;
    dfs(0,adj,st);
    //cout<<st.size();
    if(st.size()!=n){
     int count=0;
        while(count<n){
            if(st.count(count)) count++;
            else{
                cout<<"NO"<<endl;
                cout<<1<<" "<<count+1<<endl;
                break;

            }
        }
        return 0;
    }

    dfs(0,rev,st1);
   // cout<<st1.size();
   

    if(st1.size()==n){
        cout<<"YES"<<endl;
        
    }
    else{
        int count=0;
        while(count<n){
            if(st1.count(count)) 
            {
                
                count++;
            }
            else   {
                cout<<"NO"<<endl;
                cout<<count+1<<" "<<1<<endl;
                break;
            }
        }


    }
}
