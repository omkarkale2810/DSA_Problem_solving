class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        priority_queue<int, vector<int> , greater<int>> unused;

        for(int i = 0 ; i < n ; i++){
            times[i].push_back(i);
            unused.push(i);
        }
        sort(times.begin(),times.end());

        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> used;
        
        for(int i = 0; i < n ; i++){
            int start = times[i][0];
            int end = times[i][1];
            int frd = times[i][2];

            
            while(!used.empty() && start >= used.top().first){
                pair<int,int> curr = used.top();
                used.pop();
                unused.push(curr.second);
            }

            if(!unused.empty()){
                int chair = unused.top();
                unused.pop();
                if(frd == targetFriend){
                    return chair;
                }
                used.push({end,chair});
            }
        }
        return n;
    }
};