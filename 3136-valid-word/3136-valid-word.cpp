class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3){
            return false;
        }
        int cc = 0;
        int dc = 0;
        int vc = 0;
        int special = 0;

        for(char &ch : word){
            if( isalpha(ch) ){
                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
                    vc++;
                }
                else{
                    cc++;
                }
            }
            else if(!isdigit(ch)){
                return false;
            }
        }

        return vc >= 1 && cc >= 1; 

    }
};