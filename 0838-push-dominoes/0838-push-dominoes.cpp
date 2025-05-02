class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        vector<int> leftpush(n,0);
        vector<int> rightpush(n,0);
        int time = 1;
        char prev = '.';
        for(int i = 0 ; i < n ; i++){
            if(dominoes[i] == '.' && prev == 'R'){
                rightpush[i] = time;
                time++;
            }
            else if(dominoes[i] == 'L'){
                prev = 'L';
                time = 0;
            }
            else if(dominoes[i] == 'R'){
                prev = 'R';
                time = 1;
            }
        }

        int timet = 1;
        prev = '.';
        for(int i = n-1 ; i >= 0 ; i--){
            if(dominoes[i] == '.' && prev == 'L'){
                leftpush[i] = timet;
                timet++;
            }
            else if(dominoes[i] == 'R'){
                prev = 'R';
                timet = 0;
            }
            else if(dominoes[i] == 'L'){
                prev = 'L';
                timet = 1;
            }

        }
        string answer = "";
        for(int i = 0 ;i < n ; i++){
            if(leftpush[i] == 0 && rightpush[i] == 0 ){
                answer += dominoes[i];
            }
            else if( rightpush[i] == 0 ){
                answer += 'L';
            }
            else if( leftpush[i] == 0){
                answer += 'R';
            }
            else if(leftpush[i] > rightpush[i]){
                answer += 'R';
            }
            else if(leftpush[i] < rightpush[i]){
                answer += 'L';
            }
            else if(leftpush[i] == rightpush[i]){
                answer += '.';
            }
        }
        return answer;
    }
};