class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0){
            return 0; 
        }
        if (nums.size() == 1){
            return 1; 
        }
        int max_length = 1; 
        set<int> s(nums.begin(), nums.end()); 

        for (auto& num : s){
            int length = 1; 
            if (!s.count(num-1)){
                int start = num; 
                while(s.count(start+=1)){
                    length +=1;
                }
            }
            max_length = max(max_length, length); 
        }
        return max_length; 
    }
};
