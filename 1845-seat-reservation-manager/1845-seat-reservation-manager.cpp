class SeatManager {
public:
    vector<bool> hash;
    priority_queue<int, vector<int>, greater<int>> vaccant;
    int it;
    SeatManager(int n) {
        hash.resize(n,false);
        it = 1;
    }
    int reserve() {
        int temp = it;
        if(vaccant.empty()){
            it++;   
        }   
        else{
            temp = vaccant.top();
            vaccant.pop();
           
        }
        hash[temp] = true;
        return temp;
    }
    
    void unreserve(int i) {
        hash[i] = false;
        vaccant.push(i);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */