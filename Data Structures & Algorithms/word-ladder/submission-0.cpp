class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>st;
        st.insert(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        int steps=0;
        while(!q.empty()){
            int step=q.front().second;
            string origWord=q.front().first;
            if(origWord == endWord)return step;
            q.pop();
            for(int i=0;i<origWord.size();i++){
                char og=origWord[i];
            for(int j= 'a';j<='z';j++){
                origWord[i]=j;
                if(st.find(origWord)!=st.end()){
                    q.push({origWord,step+1});
                    st.erase(origWord);
                }
                else continue;
            }
            origWord[i]=og;
            }
        }
        return steps;
    }
};
