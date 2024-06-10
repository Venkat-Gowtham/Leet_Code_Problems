class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>cp=heights;
        sort(begin(cp),end(cp));
        int c= 0;
        for(int i = 0;i<heights.size();i++){
            if(heights[i]!=cp[i])c++;
        }
        return c;

    }
};