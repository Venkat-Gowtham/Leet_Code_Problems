class Node {
    public:
    Node * way[26];
    int flag=0;
    string word;
    Node()
    {
         for(int i=0;i<26;i++){
                way[i]=NULL;
            }
            // word = st;
            word = "";
    }

};

class Solution {
    private:
    Node * root = new Node();
public:
    vector<string>res;
    void dfs(vector<vector<char>>& board,int i, int j,vector<vector<int>>& vis,Node * temp)
    {
        if(i < 0 || j < 0 || i == board.size() || j == board[0].size() || board[i][j] == '0' || temp->way[board[i][j] - 'a']==NULL )return;
        temp = temp->way[board[i][j] - 'a'];
        if(temp->flag == 1)
        {
            string st = temp->word;
            res.push_back(st);
            temp->flag=0;
        }
        // vis[i][j]=1;
        // cout<<board[i][j]<<" "<<temp->flag<<endl;
        char x = board[i][j];
        board[i][j] = '0';
        dfs(board,i+1,j,vis,temp);
        dfs(board,i-1,j,vis,temp);
        dfs(board,i,j+1,vis,temp);
        dfs(board,i,j-1,vis,temp);
        board[i][j] = x;  
        // vis[i][j]=0;  
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m=board.size(),n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        // vector<string>res;
        
        for(auto it : words){
            Node * t = root;
            for(auto it2 : it){
                if(!t->way[it2-'a'])t->way[it2-'a'] = new Node();
                t = t->way[it2-'a'];
            }
            t->word = it;
            t->flag=1;
            // cout<<t->flag<<endl;
            }
            //  cout<<root->way['o'-97];
        // string store;
    //  /   dfs(board,0,0,vis,root);
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                  dfs(board,i,j,vis,root);
            }
        }
        return res;
        
            
        
    }
};