class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> s(folder.begin() , folder.end());
        vector<string> result;

        for(string currfolder : folder){
            bool flag = true;
            string temp = currfolder;
            while(!currfolder.empty()){
                size_t posi = currfolder.find_last_of('/');
                currfolder = currfolder.substr(0,posi);
                
                if( s.find(currfolder) != s.end() ){
                    flag = false;
                    break;
                }

            }
            if(flag){
                result.push_back(temp);
            }
        }
        return result;
    }
};