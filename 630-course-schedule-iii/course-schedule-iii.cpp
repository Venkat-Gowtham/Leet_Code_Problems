class Solution {
public:
    bool static comp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),comp);
        priority_queue<int>pq;
        
        int days = 0 , c = 0 ;
       for(auto it : courses){

           if(days + it[0] <= it[1]){
                days += it[0];
                pq.push(it[0]);
           }   
           else if( !pq.empty() and pq.top() >= it[0]){
            days = days - pq.top() + it[0];
            pq.pop();
            pq.push(it[0]);
           }
        }
        return pq.size();
    }
};