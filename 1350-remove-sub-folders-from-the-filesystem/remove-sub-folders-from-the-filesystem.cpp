class Trie{
    public :
    Trie *arr[27];
    bool flag ;
    Trie (){
        for(int i = 0 ; i < 27 ; i++){
            arr[i] = nullptr; // all 27 to null
        }
        flag = false;
        }
};
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(begin(folder),end(folder));
        Trie *root = new Trie();
        vector<string>result;
        for(int i = 0;i<folder.size();i++){
            Trie *temp = root;
            int n = folder[i].size(),f=0;
            for(int j=0;j<folder[i].size();j++){
                char x = folder[i][j];
                if(x=='/'){
                    if(!temp->arr[26]){
                        temp->arr[26]= new Trie();
                    }
                    if(temp->flag){f=1;break;}
                    temp = temp->arr[26];
                }
                else{
                    if(!temp->arr[x-'a']){
                        temp->arr[x-'a'] = new Trie();
                    }
                    temp = temp->arr[x-'a'];
                }
            }
            temp->flag = true;
           if(!f)result.push_back(folder[i]);
        }      
        return result;
    }
};