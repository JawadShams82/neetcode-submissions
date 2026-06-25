class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for(auto c : s){
            if(isalnum(c))
                t+=tolower(c);
        }
        string r=t;
        reverse(r.begin(),r.end());
        return t==r;
    }
};