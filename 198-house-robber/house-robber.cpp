class Solution {
public:
    int rob(vector<int>& houses) {
			if(houses.size()==1)return houses[0];
			int n=houses.size();
        vector<int>m(n);
	m[0]=(houses[0]);
	m[1]=(houses[1]);
	m[1]=max(houses[0],houses[1]);
	for(int i=2;i<n;i++){
		
		m[i]=(max(m[i-1],(houses[i]+m[i-2])));
	}
	return max(m[n-1],m[n-2]);

    }
};