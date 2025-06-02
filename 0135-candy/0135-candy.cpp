class Solution {
public:
    int candy(vector<int>& arr) {
        int n = arr.size();
        vector<int> ltr( n , 1);
        vector<int> rtl( n , 1);   

        for(int i = 1 ; i < n ; i++){
            if(arr[i] > arr[i-1]){
                ltr[i] = max(ltr[i],ltr[i-1]+1);
            }
        }    

        for(int i = n-2 ; i >= 0 ; i--){
            if(arr[i] > arr[i+1]){
                rtl[i] = max(rtl[i],rtl[i+1]+1);
            }
        }     

        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += max(ltr[i] , rtl[i]);
        }
        return sum;
        
        // Striver approach
        
        
        // int peak = 0;
        // int down = 0;
        // int sum = 1;
        // int i = 1;

        // while(  i < n ){

        //     if(arr[i] == arr[i-1]){
        //         sum += 1 ;
        //         i++;
        //         continue;
        //     }
        //     peak = 1;
        //     while( i<n && arr[i] > arr[i-1]){
        //         peak+=1;
        //         sum += peak;
        //         i++;
        //     }
        //     down = 1;
            
        //     while(i < n &&  arr[i] < arr[i-1]){
        //         sum += down;
        //         down += 1;
        //         i++;
        //     }
        //     if(down > peak){
        //         sum += down-peak;
        //     }
        // }
        // return sum;
        
    }
};