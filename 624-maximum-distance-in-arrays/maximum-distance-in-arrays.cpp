class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int fma = -1,sma=-1,fmi=-1,smi=-1;
        for(int i = 0;i<arr.size();i++){
            int m = arr[i].size() -1;
            int q = fma!=-1?arr[fma].size()-1:-1;
            int v = sma!=-1?arr[sma].size()-1:-1;
            if(fma == -1 or (q!=-1 and arr[i][m]>=arr[fma][q])){
                    sma = fma;
                    fma = i;
                    // f=1;
            }
            else if(sma == -1 or(v!=-1  and arr[i][m]>arr[sma][v])){
                sma = i;
            }
            if(fmi == -1 or arr[i][0]<=arr[fmi][0]){
                smi = fmi;
                fmi = i;
            }
            else if(smi == -1 or arr[i][0]<arr[smi][0]){
                smi = i;
            }
        }
        int u = 0 , v = 0,w = 0 , x = 0;
        if(fma!=fmi and fma!=-1 and fmi!=-1){
            int fl = arr[fma].size()-1;
            u = abs(arr[fma][fl]-arr[fmi][0]);
        }
        if(fma!=smi and fma!=-1 and smi!=-1){
            int fl = arr[fma].size()-1;
            v = abs(arr[fma][fl]-arr[smi][0]);
        }
        if(sma!=fmi and sma!=-1 and fmi!=-1){
            int fl = arr[sma].size()-1;
            w = abs(arr[sma][fl]-arr[fmi][0]);
        }
        if(sma!=smi and sma!=-1 and smi!=-1){
            int fl = arr[sma].size()-1;
            x = abs(arr[sma][fl]-arr[smi][0]);
        }
       if(fma!=-1)cout<<arr[fma][arr[fma].size()-1]<<endl;
    if(sma!=-1)cout<<arr[sma][arr[sma].size()-1]<<endl;
    if(fmi!=-1)cout<<arr[fmi][0]<<endl;
    if(smi!=-1)cout<<arr[smi][0]<<endl;
        return max({u,v,w,x});

        
    }
};