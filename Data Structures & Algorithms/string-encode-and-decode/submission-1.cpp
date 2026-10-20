class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.size() == 0) return "";
        int n = strs.size();
        vector<int> s;
        string encodedS = "";
        for(auto it:strs){
            s.push_back(it.length());
            encodedS+= it;
        }

        string encoded = "";
        for(auto it:s){
            encoded+= to_string(it);
            encoded+= ",";
        }

        encoded+= "#" + encodedS;
        cout<<"encoded"<<encoded;
        return encoded;
    }

    vector<string> decode(string s) {
        if(s.size() == 0) return {};

        vector<int> ls;
        int pos;
        string num;
        for(int i=0; i<s.size(); ++i){
            if(s[i] == '#'){
                pos = i+1;
                break;
            }
            if(s[i] == ','){
                ls.push_back(stoi(num));
                num.clear();
                continue;
            }

            num.push_back(s[i]);
        }

        vector<string> decoded;
        for(auto it:ls){
            string temp = "";
            for(int i=0; i<it; ++i){
                temp+= s[pos+i];
            }
            decoded.push_back(temp);
            pos+= it;
        }

        return decoded;
    }
};