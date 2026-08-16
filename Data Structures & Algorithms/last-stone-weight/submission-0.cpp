class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq; 
        for(auto x: stones) pq.push(x);
        while(pq.size() > 1){
            auto x1 = pq.top(); 
            pq.pop(); 
            auto x2 = pq.top(); 
            pq.pop();
            pq.push(x1-x2);
        }
        if(pq.empty()) return 0; 
        return pq.top();
    }
};
