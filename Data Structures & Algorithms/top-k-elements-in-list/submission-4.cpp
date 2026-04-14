class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq_map; 

        for (int i = 0; i < nums.size(); i++) {
            if (freq_map.count(nums[i])) {
                freq_map[nums[i]]++; 
            } else {
                freq_map[nums[i]] = 1; 
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, 
            greater<pair<int, int>>> top_k;  

        for (auto& entry : freq_map) {
            top_k.push({entry.second, entry.first}); 
            if (top_k.size() > k) {
                top_k.pop(); 
            }
        }
        vector <int> res; 
        for (int i = 0; i < k; i++) {
            res.push_back(top_k.top().second); 
            top_k.pop(); 
        }
        return res; 
    }
};