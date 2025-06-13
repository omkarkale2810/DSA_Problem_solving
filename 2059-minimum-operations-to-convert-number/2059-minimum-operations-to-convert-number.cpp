class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int n = nums.size();
        vector<bool> visited(1001,false);
        queue<int> q;
        q.push(start);
        int step = 0;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                int curr = q.front();
                q.pop();

                if(curr == goal){
                    return step;
                }

                if(curr<0 || curr>1000 || visited[curr]==1) continue;

                visited[curr] = true;
                for(int i = 0 ; i < n ; i++){
                    int add = nums[i] + curr;
                    int sub = curr    - nums[i];
                    int xorr = curr ^ nums[i];
                    q.push(add);
                    q.push(sub);
                    q.push(xorr);
              
                } 
            }
            step++;
        }
        return -1;
    }
};