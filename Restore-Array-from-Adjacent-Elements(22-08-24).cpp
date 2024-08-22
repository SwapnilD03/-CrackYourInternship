class Solution {
public:
  
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size() + 1;

        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> indegree;
        for (auto& pair : adjacentPairs) {
            adj[pair[0]].push_back(pair[1]);
            adj[pair[1]].push_back(pair[0]);
            indegree[pair[0]]++;
            indegree[pair[1]]++;
        }

        int start;
        for (auto& [node, deg] : indegree) {
            if (deg == 1) {
                start = node;
                break;
            }
        }

    
        int curr = start, prev = INT_MIN;
        vector<int> nums;
        while (nums.size() < n) {
            nums.push_back(curr);
            for (auto& neighbour : adj[curr]) {
                if (neighbour != prev) {
                    prev = curr;
                    curr = neighbour;
                    break;
                }
            }
        }
        return nums;
    }
};
