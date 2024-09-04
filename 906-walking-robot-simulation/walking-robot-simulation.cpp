class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int f = 0;
        int n = commands.size();
        int ma = 0 , x = 0 , y = 0;
        map<pair<int,int>,int>mp;
        for(auto it : obstacles){
            mp[{it[0],it[1]}]++;
        }
        for(int i = 0;i<n;i++){
            int prev = f;
            int flag = 0;
            if(commands[i] == -1){ 
                f=(f+1)%4;
            }
            else if(commands[i] == -2){
                f = f-1;
                if(f<0)f+=4;
            }
            else{
                // flag = 0;
                int k = commands[i];
                if(f==0){
                    for(int i = 1;i<=k;i++)
                    {
                            if(mp.count({x,y+i}))
                             {
                               y+=i-1;
                                flag = 1;
                                break;
                            }
                    }
                  if(!flag)y+=k;
                }
                else if(f==1){
                    for(int i = 1;i<=k;i++){
                        if(mp.count({x+i,y})) {
                            x=x+i-1;
                            flag = 1;
                            break;
                        }
                    }
                    if(!flag)x+=k;
                }
                else if(f==2){
                    for(int i = 1;i<=k;i++){
                        if(mp.count({x,y-i})) {
                            y=y-i+1;
                            flag = 1;
                            break;
                        }
                    }
                    if(!flag)y-=k;
                }
                else if(f==3){
                    for(int i = 1;i<=k;i++){
                        if(mp.count({x-i,y})) {
                            x=x-i+1;
                            flag = 1;
                            break;
                        }
                    }
                    if(!flag)x-=k;
                }
            }
            ma = max(1LL*abs(x)*abs(x)+1LL*abs(y)*abs(y),1LL*ma);
        }
        return 1LL*ma;
    }

};