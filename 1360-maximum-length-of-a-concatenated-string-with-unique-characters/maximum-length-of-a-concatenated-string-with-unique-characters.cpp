class Solution {
public:
int total=0;
  int findmax(vector<string>&arr,int res,int ind)
    {
        if(ind>=arr.size())
        {
            return 0;
        }
        int fl=0,ans=0,pc=0,npc=0;
        for(int i=0;i<arr[ind].size();i++)
        {
                if(res&(1<<(arr[ind][i]-'a')))
                {
                    fl=1;
                    // break;
                }
                else
                {
                    res+=1<<(arr[ind][i]-'a');
                }
                if(fl==1)
                {
                    for(int j=i-1;j>=0;j--)
                    {
                        res-=1<<(arr[ind][j]-'a');
                    }
                    break;
                }
        }
        if(!fl)
        {
           pc=findmax(arr,res,ind+1)+arr[ind].size();
            for(int i=0;i<arr[ind].size();i++)
            {
                res-=1<<(arr[ind][i]-'a');
            }
        }
       npc= findmax(arr,res,ind+1);
       return max(pc,npc);

    }
    int maxLength(vector<string>& arr) {
        int res=0,ma=0;
        return findmax(arr,res,0);
    }
};