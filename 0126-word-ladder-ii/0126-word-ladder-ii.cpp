#include <utility> // For std::move

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        vector<vector<string>> ans;

        if (wordSet.find(endWord) == wordSet.end()) return ans;

        wordSet.erase(beginWord);

        queue<string> q;
        q.push(beginWord);

        unordered_map<string, vector<string>> prev; // for backtracking
        unordered_map<string, int> dist; // distance from beginWord
        dist[beginWord] = 0;

        bool found = false;

        while (!q.empty()) {
            int level_size = q.size();
            unordered_set<string> visited_this_level;

            if (found) break;

            for (int i = 0; i < level_size; ++i) {
                string p = q.front(); q.pop();
                string temp_word = p;

                for (int j = 0; j < temp_word.length(); ++j) {
                    char original_char = temp_word[j];

                    for (char c = 'a'; c <= 'z'; ++c) {
                        temp_word[j] = c;

                        if (wordSet.count(temp_word)) {
                            // First time reaching this word
                            if (dist.find(temp_word) == dist.end()) {
                                dist[temp_word] = dist[p] + 1;
                                prev[temp_word].push_back(p);
                                q.push(temp_word);
                                visited_this_level.insert(temp_word);
                            }
                            // Found another path of same length
                            else if (dist[temp_word] == dist[p] + 1) {
                                prev[temp_word].push_back(p);
                            }

                            if (temp_word == endWord) {
                                found = true;
                            }
                        }
                    }

                    temp_word[j] = original_char; // revert change
                }
            }

            // Prune visited words from the set to avoid revisiting
            for (const auto& word : visited_this_level) {
                wordSet.erase(word);
            }
        }

        if (found) {
            vector<string> path;
            dfs(endWord, beginWord, prev, path, ans);
        }

        return ans;
    }

private:
    void dfs(const string& cur, const string& beginWord,
             unordered_map<string, vector<string>>& prev,
             vector<string>& path, vector<vector<string>>& ans) {

        path.push_back(cur);

        if (cur == beginWord) {
            vector<string> result = path;
            reverse(result.begin(), result.end());
            ans.push_back(std::move(result)); // move to avoid copy
        } else if (prev.count(cur)) {
            for (const string& precursor : prev.at(cur)) {
                dfs(precursor, beginWord, prev, path, ans);
            }
        }

        path.pop_back(); // backtrack
    }
};