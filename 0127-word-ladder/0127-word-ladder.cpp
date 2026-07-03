class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q ;
        unordered_set<string> st(wordList.begin(), wordList.end());
        int level=0;
        q.push({beginWord,1});
        while(!q.empty()){
            string w=q.front().first;
            level=q.front().second;
            q.pop();
            if (w == endWord) return level;
            for(int i=0;i<w.length();i++){
                char original = w[i];
                for(char ch='a';ch<='z';ch++ ){
                    w[i]=ch;
                    if(st.find(w)!=st.end()){
                        q.push({w,level+1});
                        st.erase(w);
                    }
                }
                w[i]=original;
            }
        }
        return 0;
    }
};