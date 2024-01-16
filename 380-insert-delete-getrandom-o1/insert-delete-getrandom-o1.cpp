class RandomizedSet {
public:
    set<int>st;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        int n=st.size();
        st.insert(val);
        if(st.size()==n)return false;
        return true;
    }
    
    bool remove(int val) {
        if(st.erase(val))return 1;
        return 0;
    }
    
    int getRandom() {
       return  *next(st.begin(),rand()%st.size());
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */