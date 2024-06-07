//BRUTE FORCE SOLUTION: 
// class Solution {
// public:
//     string replaceWords(vector<string>& dictionary, string sentence) {
//         for (auto it : dictionary) {
//             for (int i = 0; i <= sentence.size() - it.size(); i++) {
//                 if (sentence.substr(i, it.size()) == it &&
//                     (i == 0 || !isalnum(sentence[i - 1]))) {
//                     int j = i + it.size();
//                     while (j < sentence.size() && sentence[j] != ' ') {
//                         j++;
//                     }
//                     sentence.erase(i + it.size(), j - (i + it.size()));
//                 }
//             }
//         }
//         return sentence;
//     }
// };




class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> dictSet(dictionary.begin(), dictionary.end());
        istringstream sStream(sentence);
        string word;
        string newSentence;

        while(getline(sStream, word, ' ')){
            newSentence += shortestRoot(word, dictSet) + ' ';
        }

        newSentence.pop_back(); //remove extra space at the end added due to ^
        return newSentence;
    }

private:
    string shortestRoot(string word, unordered_set<string> dictSet){
        for(int i=1; i<=word.length(); i++){
            string root = word.substr(0, i);
            if(dictSet.contains(root)){
                return root;
            }
        }
        return word;
    }
};