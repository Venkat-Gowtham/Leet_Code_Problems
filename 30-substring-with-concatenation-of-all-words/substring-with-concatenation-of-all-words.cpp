
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        unordered_map<string, int> mp;
        unordered_map<string, int> np;
        unordered_map<int, int> visited;
        vector<int> res,indx;
        unordered_set<int>st;
        int l = words[0].length();
        int n = s.length();
        for (auto it : words) {
            mp[it]++;
            np[it]++;
        }
        if(l>n) return {};
        for (int i = 0; i <= s.size() - l; i++) {
            string temp;
            for (int j = i; j < i + l; j++) {
                temp += s[j];
            }
            if (mp.find(temp)!=mp.end()) {
                indx.push_back(i);
            }
        }

        int k = words[0].length() * words.size();
        for (int p = 0; p < indx.size(); p++) {
            if (visited.find(indx[p]) == visited.end()) {
                visited[indx[p]]++;
                int i = indx[p], j = indx[p];
                mp=np;
                if (i + k <=n) {
                    string cur = "";
                    int f = 0;
                    while (j <n) {
                        cur += s[j];
                        if ((j-i+ 1) % l == 0) {
                            if (mp.find(cur) == mp.end()) {
                                f = 1;
                                break;
                            } else {
                                mp[cur]--;
                                if (mp[cur] < 0) {
                                    while (mp[cur] < 0) {
                                        string sub = s.substr(i,l);
                                        mp[sub]++;
                                        i = i + l;
                                    }
                                    visited[i]=1;
                                }
                            }
                            cur="";
                        }
                        if(j-i+1==k){
                            st.insert(i);
                            string sub = s.substr(i,l);
                            i=i+l;
                            mp[sub]++;
                            visited[i]=1;
                        }
                        j++;
                    }
                    if (f)
                        continue;
                } else
                    break;
            }
        }

        return vector<int>(st.begin(),st.end());

        // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17
        // b a r f o o t h e f  o  o  b  a  r  m a  n

        // 0,3,6,9,12
    }
};