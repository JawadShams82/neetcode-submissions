class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>p;
        for(int i=0;i<position.size();i++)
            p.push_back({position[i],speed[i]});
        sort(p.rbegin(),p.rend());
        vector<double>s;
        for(auto i : p){
            double time=(double)(target-i.first)/i.second;
            if(s.empty() || time>s.back())
                s.push_back(time);
        }
        return s.size();
    }
};
