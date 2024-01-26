class Solution {
public:
  set<vector<string>>res;
    bool ispal(string &temp)
    {
        int i=0,j=temp.length()-1;
        while(i<j)
        {
            if(temp[i]!=temp[j])return 0;
            i++;
            j--;
        }
        return 1;
    }
    void findall(string s, int ind ,vector<string>&temp,int f)
    {
        if(ind>=s.length())
        {
            if(f==s.length())
            {
             res.insert(temp);   
            }
            return ;
        }
       string val;
       for(int i=ind;i<s.length();i++)
       {
           val+=s[i];
           if(ispal(val))
           {
               int x=val.length();
               temp.push_back(val);
               findall(s,i+1,temp,f+x);
               temp.pop_back();
           }
       }
    }
    vector<vector<string>> partition(string s) {
        int n=s.length();
        vector<string>temp;
        int f=0;
        findall(s,0,temp,f);
        vector<vector<string>>result(res.begin(),res.end());
        return result;
    }
};