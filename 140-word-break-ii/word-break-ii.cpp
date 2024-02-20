struct Node{
    
    int flag=0;
    Node* dic[26]={nullptr};
    string word;
    Node()
    {
        flag=0;
        word="";
    }
};
  void isthere(string &s, int ind , Node * temp, Node *root , vector<string>&res, string val)
    {
        if(ind == s.length()-1)
        {
            if(temp->dic[s[ind]-'a'] and temp->dic[s[ind]-'a']->flag)
            {
                string x = temp->dic[s[ind]-'a']->word;
                res.push_back(val+x);
            }
            return ;
        }
        temp = temp->dic[s[ind]-'a'];
        if(!temp)return ;
        bool pick=0 , np = 0;
        if(temp->flag)
        {

           isthere(s,ind+1,root,root, res, val+temp->word+" ");
        }
       isthere(s,ind+1,temp,root,res, val);
    }
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>res;
         Node *root = new Node();
        for(auto it : wordDict)
        {
            Node * temp = root;
            string what;
            for(auto ele : it)
            {
                what+=ele;
                if(!temp->dic[ele-'a'])
                {
                    temp->dic[ele-'a'] = new Node();
                    temp = temp->dic[ele-'a'];
                }
                else
                {
                    temp = temp->dic[ele-'a'];
                }
            }
            temp->flag=1;
            temp->word = what;
        }
        string word;
        isthere(s,0,root,root,res,word);
        return res;
    }
};