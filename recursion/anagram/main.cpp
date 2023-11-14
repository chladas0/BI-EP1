#include <iostream>
#include <algorithm>

using namespace std;

string word;
int usedIdx[20], len, cnt = 0;
char anagram [20];

void generate(int idx) {
    // end of the word
    if(idx == len){
        anagram[idx] = '\0';
        cout << anagram << '\n';
        ++cnt; return;
    }
    bool usedChars [26] = {};
        // try all possible unused letters on the current position and generate the rest
        for(int i = 0; i < word.size(); ++i){
            if(usedIdx[i] || usedChars[word[i] - 'a']) continue;
            usedIdx[i] = 1;
            anagram[idx] = word[i];
            generate(idx+1);
            usedIdx[i] = 0;
            usedChars[word[i] - 'a'] = true;
        }
}

int main() {
    std::ios::sync_with_stdio(false);

    while(cin >> len && len != 0){
        cnt = 0; cin.ignore(); getline(cin, word); sort(word.begin(), word.end());
        generate(0);
        cout << cnt << '\n';
    }
    return 0;
}