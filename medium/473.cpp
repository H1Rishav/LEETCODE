class Solution {
	// a,b,c,d are four sides of square
    int a,b,c,d;
    bool fun(vector<int>& matchsticks,int i){
       if(i==matchsticks.size()){
        if(a==0&&b==0&&c==0&&d==0)return true;
        else return false;
        
       }

       if(matchsticks[i]<=a)
       {
        a-=matchsticks[i];
        if ( fun(matchsticks,i+1)) return true;//returning here itself so that bracnhes are pruned further
        //
        a+=matchsticks[i];
       }
        
        if(matchsticks[i]<=b){
            b-=matchsticks[i];
            if(fun(matchsticks,i+1)) return true;
            b+=matchsticks[i];        // backtrack step                    
        }
        
        if(matchsticks[i]<=c){
            c-=matchsticks[i];
            if(fun(matchsticks,i+1)) return true;
            c+=matchsticks[i];         // backtrack step
        }
        
        if(matchsticks[i]<=d){
            d-=matchsticks[i];
            if(fun(matchsticks,i+1)) return true;
            d+=matchsticks[i];         // backtrack step
        }
		
		//If none of the explored option retuen true then  we have to return false
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        //had to follow solutions to be able to do this
        //worst case scenarion 4^N but it never reaches that extent hence should be fine
		if(matchsticks.size()<4)return false;

        int sizesum=accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(sizesum%4!=0)return false;

        a=sizesum/4;
        b=sizesum/4;
        c=sizesum/4;
        d=sizesum/4;
        //having the bigger ones in the begnning itself prunes them hence no unrquired bracnhes 
        //so logic is we might keep going down thinking we will find the perfect addition to makeequal but get hit witha  large matchstick but if we use the larger branch first itself we realise that it is not possible so that branch is never extended
        
        sort(matchsticks.rbegin(),matchsticks.rend());
        
		return fun(matchsticks,0);
    }
};