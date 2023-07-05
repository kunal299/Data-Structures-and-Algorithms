/*
    Time Complexity - O(n * wordLen * 26)
    Space Complexity - O(n) 
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;

        q.push({beginWord, 1});
        st.erase(beginWord);

        while(!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;

            q.pop();

            if(word == endWord) return steps;

            for(int i=0; i<word.length(); i++) {
                char original = word[i];
                
                for(char ch='a'; ch<='z'; ch++) {
                    word[i] = ch;
                    if(st.find(word) != st.end()) {
                        q.push({word, steps + 1});
                        st.erase(word);
                    }
                } 

                word[i] = original;
            }
        }

        return 0;

    }
};