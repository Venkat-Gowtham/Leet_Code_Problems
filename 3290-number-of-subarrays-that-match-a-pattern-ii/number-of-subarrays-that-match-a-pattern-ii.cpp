class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        string text,pat;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1])text+="2";
            else if(nums[i]<nums[i+1])text+="1";
            else text+="0";
        }
        for(int i=0;i<pattern.size();i++)
        {
            if(pattern[i]==1) pat+="1";
            else if(pattern[i]==0)pat+="0";
            else pat+="2";
        }
        int i=0,j=1,cnt=0;
        vector<int>lps(pat.size(),0);
        while(j<pat.size())
        {
            if(pat[i]==pat[j])
            {
                lps[j]=i+1;
                i++;
                j++;
            }
            else if(i!=0)i=lps[i-1];
            else {lps[j]=0;j++;}
        }
        i=0,j=0;
        while(i<text.size())
        {
            if(pat[j]==text[i])
            {
                i++;
                j++;
                if(j==pat.size())
                {
                    j=lps[j-1];
                    cnt++;
                }
            }
            else
            {
                if (j==0)i++;
                else j=lps[j-1];
            }  
        }
        return cnt;
        
    }
// };
// string a = "";
//         for (int i=0; i<nums.size()-1; i++){
//             if (nums[i+1]>nums[i])a += "1";
//             else if (nums[i+1]==nums[i])a += "0";
//             else a += "2";
//         }
//         string b = "";
//         for (auto it : pattern){
//             if (it==1)b += "1";
//             else if (it==0)b += "0";
//             else b += "2";
//         }
//         int n = a.size(),m = b.size();
//         vector<int>lps(m,0);
//         int i=0,j=1;
//         while (j<m){
//             if (b[i]==b[j]){
//                 lps[j] = i+1;
//                 i++;
//                 j++;
//             }
//             else if (i!=0)i = lps[i-1];
//             else{
//                 lps[j] = 0;
//                 j++;
//             }
//         }
//         i = j = 0;
//         int cnt = 0;
//         while (i<n){
//             if (a[i]==b[j]){
//                 i++;
//                 j++;
//                 if (j==m){
//                     cnt++;
//                     j = lps[j-1];
//                 }
//             }
//             else{
//                 if (j==0)i++;
//                 else j = lps[j-1];
//             }
//         }
//         return cnt;
};