class Solution {
public:
    int maxDistance(string s) {
        int  n=s.length();
        int upc=0,lc=0,count=0;
        for(int i=0;i<n;i++)
            {
                if(s[i]=='U')
                    upc++;
                else if(s[i]=='D')
                    upc--;
                else if(s[i]=='L')
                    lc++;
                else if(s[i]=='R')
                    lc--;
                else 
                    count++;
            }
        int x=(int)abs(upc)+(int)abs(lc)+count;
        return x;
        
    }
};