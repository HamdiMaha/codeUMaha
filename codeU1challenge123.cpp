#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// Challenge 1
bool checkAnagram(string anagram1, string anagram2) {
	if (anagram1.size() != anagram2.size()){
		return false;
	}
	transform(anagram1.begin(), anagram1.end(),  anagram1.begin(), ::tolower);
	transform(anagram2.begin(), anagram2.end(),  anagram2.begin(), ::tolower);
	sort(anagram1.begin(), anagram1.end());
	sort(anagram2.begin(), anagram2.end());
	for (int i = 0; i < anagram1.size(); i++) {
	 	if (anagram1[i] != anagram2[i]) {
	 		return false;
	 	}
		else {
			return true;
		}
	}
}
// Challenge 2
bool checkAnagramSentence(string anagram1, string anagram2) {
	string sentence1, sentence2;
	for(int i = 0; i < anagram1.size(); i++) {
		if (!isspace(anagram1[i]) && !ispunct(anagram1[i])) {
			sentence1.push_back(anagram1[i]);
		}
	}
	for(int i = 0; i < anagram2.size(); i++) {
		if (!isspace(anagram2[i]) && !ispunct(anagram2[i])) {
			sentence2.push_back(anagram2[i]);
		}
	}
	return checkAnagram (sentence1, sentence2);
	
}
// Challenge 3
	bool checkWordsSentences(string anagram1, string anagram2) {
		string word1, word2;
		if (anagram1.size() != anagram2.size()) {
			return false;
		}
		for(int i = 0; i < anagram1.size(); i++) {
 			if (!isspace(anagram1[i]) ) {
 				word1.push_back(anagram1[i]);
 				word2.push_back(anagram2[i]);
			}
			else {
				bool descision = checkAnagram(word1, word2);
				word1.clear();
				word2.clear();
			}
		}
		return descision;
	}
	void finalDecision(bool decision) {
		if (decision) {
			cout << "Anagrams";
		}
		else {
			cout << "Not Anagrams";
		}
	}
int main() {
	string anagram1; cin >> anagram1;
	string anagram2; cin >> anagram2;
	bool decision = checkAnagram(anagram1, anagram2);
	finalDecision(decision);
	bool decisionSentence = checkAnagramSentence(anagram1, anagram2);
	finalDecision(decisionSentence);
	bool decisionWordSentence = checkWordsSentences(anagram1, anagram2);
	finalDecision(decisionWordSentence);
	
	return 0;
}