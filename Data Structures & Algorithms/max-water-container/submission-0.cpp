class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans=0;
        int left=0,right=heights.size()-1;
        
        while(left<right){
            int width=right-left;
            
            ans=max(ans,min(heights[left],heights[right])*width);
            
            if(heights[left] <= heights[right])
               left++;
            else
               right--;
        }
        return ans;
    }
};
