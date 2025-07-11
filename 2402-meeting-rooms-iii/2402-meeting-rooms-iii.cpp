class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());

        vector<int> count(n,0);

        priority_queue< int, vector<int> , greater<int> > availroom;
        priority_queue< pair<long long,int> , vector<pair<long long,int>> , greater<pair<long long,int>> > usedroom;

        for(int i = 0 ; i < n ; i++){
            availroom.push(i);
        }

        for(vector<int> &it: meetings){
            int start = it[0];
            int end   = it[1];
            int duration = end - start;
            
            while(!usedroom.empty() && usedroom.top().first <= start){
                int room = usedroom.top().second;
                usedroom.pop();
                availroom.push(room);
            }

            if(!availroom.empty()){
                int room = availroom.top();
                availroom.pop();
                usedroom.push({end , room});
                count[room]++;
            }
            else{
                pair<long long, int> curr = usedroom.top();
                usedroom.pop();
                usedroom.push({curr.first + duration , curr.second}); 
                count[curr.second]++;
            }
        }
        int idx = -1;
        int maxval = -1;
        for(int i = 0; i < n ; i++){
            if(maxval < count[i]){
                maxval = count[i];
                idx = i;
            }
        }
        return idx;
    }
};