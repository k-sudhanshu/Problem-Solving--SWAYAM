//recursive
class Solution {
public:
    
    int Pick(vector<int> v, int k, int i, int j){
        if(i>j || k==0){
            return 0;
        }
        int left = v[i]+Pick(v,k-1,i+1,j);
        int right = v[j]+Pick(v,k-1,i,j-1);
        int sum = max(left,right);
        return sum;
    }
    
    int maxScore(vector<int>& cardPoints, int k) {
        return Pick(cardPoints,k,0,cardPoints.size()-1);
    }
};
