class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> words1, words2;
        
        // Split sentence1 into words
        stringstream s1(sentence1);
        string word;
        while (s1 >> word) {
            words1.push_back(word);
        }

        // Split sentence2 into words
        stringstream s2(sentence2);
        while (s2 >> word) {
            words2.push_back(word);
        }

        int n1 = words1.size();
        int n2 = words2.size();

        if (n1 < n2) {
            swap(words1, words2); // Ensure words1 is always the longer one
            swap(n1, n2);
        }

        // Check for prefix match
        int i = 0;
        while (i < n2 && words1[i] == words2[i]) {
            i++;
        }

        // Check for suffix match
        int j = 0;
        while (j < n2 && words1[n1 - 1 - j] == words2[n2 - 1 - j]) {
            j++;
        }

        // The combined length of prefix and suffix match should cover the entire shorter sentence
        return i + j >= n2;
    }
};
