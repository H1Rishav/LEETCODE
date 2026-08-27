class Solution {
public:
    int minLights(vector<int>& lights) {

        int contc=0;
        int n=lights.size();
        vector<int>ans(n+1,0);
        int rc=0;
        for(int i=0;i<n;i++)
            {
                if(lights[i]==0 )continue;
                
                int l=max(i-lights[i],0);
                int r=min(n-1,i+lights[i]);
                ans[l]++;
                ans[r+1]--;
            }
        int sc=0;int req=0;
        for(int i=0;i<n;i++)
            {
                sc+=ans[i];
                
                if(sc==0)
                {
                    contc++;
                    
                }
                else{
                    if(contc!=0)
                    {
                       // cout<<contc;
                        req+=(int)ceil(1.0*contc/3.0);
                        contc=0;
                    }
                }
            }
        if(contc!=0)
        {
            req+=(int)ceil(1.0*contc/3.0);
        }
        return req;
    }
};