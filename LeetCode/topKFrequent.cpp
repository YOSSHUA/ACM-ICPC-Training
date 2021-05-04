//Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(k == nums.size()){
            return nums;
        }
        map<int, int> cont;
        for(int v:nums){
            cont[v]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto it:cont){
            pq.push(make_pair(it.second, it.first));
        }
        vector<int> ans;
        int i = 0;
        while(i < k){
            pair<int, int> cur = pq.top(); 
            ans.push_back(cur.second);
            pq.pop();
            i++;
        }
        return ans;
    }
};
