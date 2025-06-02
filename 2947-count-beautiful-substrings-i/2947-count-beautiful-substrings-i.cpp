class Solution {
public:
    #define ll long long

    bool isvowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    long long beautifulSubstrings(string s, int k) {
        int n = s.length();

        ll vowel = 0;
        ll consonants = 0;
        ll count = 0;

        unordered_map< int , unordered_map<int,int> > mp;
        mp[0][0] = 1;
        
        for(char &ch : s){
            if(isvowel(ch)){
                vowel++;
            }
            else{
                consonants++;
            }

            ll psum = (vowel - consonants);

            for(auto &[pastvowelcount , pcount]: mp[psum]){

                ll curr_sub_vowel_count = vowel - pastvowelcount;

                if(curr_sub_vowel_count*curr_sub_vowel_count % k == 0){
                    count +=  pcount;
                }
            }
            mp[psum][vowel%k]++;
        }
        return count;
    }
};