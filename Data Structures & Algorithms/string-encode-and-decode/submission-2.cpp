class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.size() == 0) return "";
        string encoded;
        for(auto it:strs){
            encoded.append(to_string(it.length()));
            encoded.push_back('#');
            encoded.append(it);
        }
        return encoded;
    }// tc - O(m+n), sc - (m+n)

    vector<string> decode(string s) {
        vector<string> decoded;
        int i=0;
        while(i<s.size()){
            int j = i;
            while(s[j] != '#') j++;

            int len = stoi(s.substr(i, j-i));

            i = j+1;
            decoded.push_back(s.substr(i, len));
            i+= len;
        }

        return decoded;
    }
};