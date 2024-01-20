class Solution {
public:
int sumSubarrayMins(vector<int>& arr) {
        stack<pair<int,int>>st1;
        stack<pair<int,int>>st2;
        vector<long long int>l(arr.size());
        vector<long long int>r(arr.size());
        for(int i=0;i<arr.size();i++)
        {
            if(st1.empty())
            {
                st1.push({arr[i],1});
                l[i] = 1;
            }
            else
            {
                int c = 1;
                while(!st1.empty() and st1.top().first > arr[i])
                {
                    c += st1.top().second;
                    st1.pop();
                    
                }
                st1.push({arr[i],c});
                l[i] = c;
            }
        }
        for(int i=arr.size()-1;i>=0;i--)
        {
            if(st2.empty())
            {
                r[i] = 1;
                st2.push({arr[i],1});
            }
            else
            {
                int c = 1;
                while(!st2.empty() and st2.top().first >= arr[i])
                {
                    c += st2.top().second;
                    st2.pop();
                    
                }
                st2.push({arr[i],c});
                r[i] = c;
            }
        }
        long long int res = 0;
        int m = 1e9+7;
        for(int i=0;i<arr.size();i++)
        {
            res = (res + (l[i] * r[i] % m) * arr[i] % m) % m;
        }
        return res;
    }
};