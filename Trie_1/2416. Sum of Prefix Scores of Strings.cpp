class trie{//make trie class
public:
    int cnt;
    trie* v[26];
    trie(){
        cnt = 0;//no of common prefix
        for(int i = 0; i < 26; i++){
            v[i] = NULL;
        }
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        trie *node = new trie(),*tmp;
         //inittilize trie root node
        for(auto &i: words){
            tmp = node;
            for(auto &j: i){
                if(tmp->v[j-'a']==NULL){
                   //if node not found make node
                    tmp->v[j-'a'] = new trie();
                    tmp = tmp->v[j-'a'];
                    tmp->cnt++;
                }else{
                    //if node found
                    tmp = tmp->v[j-'a'];
                    tmp->cnt++;//increment prefix count by one
                }
            }
        }
        int sum = 0;
        vector<int> ans;
        for(auto &i: words){
            sum = 0;// for string i ans = 0
            tmp = node;
            for(auto &j: i){
                sum += (tmp->v[j-'a'])->cnt;//add no of common prefix
                tmp = tmp->v[j-'a'];
            }
            ans.push_back(sum);
        }
        return ans;
    }
}; 
