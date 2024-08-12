class KthLargest {
private :
    int K;
    vector<int>arr;
    int size ;
public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        size
         = nums.size();
        for(int i = 0;i<nums.size();i++){
            auto it = lower_bound(begin(arr),end(arr),nums[i]);
            if(it == arr.end()) arr.push_back(nums[i]);
            else arr.insert(it,nums[i]);
        }
    }
    int add(int val) {
           auto it = lower_bound(begin(arr),end(arr),val);
            if(it == arr.end()) arr.push_back(val);
            else arr.insert(it,val);
            size++;
            return arr[size-K];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */