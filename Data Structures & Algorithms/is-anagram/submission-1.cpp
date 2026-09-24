class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        map<char, int> mS, mT;
        for(int i=0; i<s.size(); ++i){
            mS[s[i]]++;
            mT[t[i]]++;
        }

        if(mS.size()!=mT.size()) return false;

        auto it1=mS.begin(), it2=mT.begin();
        while(it1!=mS.end() && it2!=mT.end()){
            if(it1->first!=it2->first || it1->second!=it2->second){
                return false;
            }
            it1++, it2++;
        }

        return true;
    }
};