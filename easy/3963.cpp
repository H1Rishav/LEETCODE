class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        for(int i=0;i<m;i++)
            {
                string att="";
                for(int j=0;j<n;j++)att+='#';
                ans.push_back(att);
            }
        for(int i=0;i<n;i++)
            ans[m-1][i]='.';
        for(int i=0;i<m;i++)
            ans[i][0]='.';
        return ans;
    }
};