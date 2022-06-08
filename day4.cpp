//
// Created by alex.cohen on 6/8/2022.
//

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

#include "day4.h"

using namespace std;

bool isValid(const string &str);

bool isAnagram(const string &str1, const string &str2);

void dayFour() {
    ifstream input("day4.txt");
    string str;
    int total = 0;
    while (getline(input, str))
        total += isValid(str);

    cout << total;
}

bool isValid(const string &str) {
    stringstream phrase(str);
    string s;
    vector<string> words;
    bool valid = true;
    while (!phrase.eof()) {
        phrase >> s;
        words.push_back(s);
    }


    for (int i = 0; i < words.size(); i++)
        for (int j = i + 1; j < words.size(); ++j)
            if (words[j] == words[i] || isAnagram(words[j], words[i]))
                valid = false;
    return valid;
}

bool isAnagram(const string &str1, const string &str2) {
    int letters[26];
    for (int &letter: letters)
        letter = 0;

    for (char i: str1) {
        int index = (int) i - 97;
        letters[index] += 1;
    }

    for (char i: str2) {
        int index = (int) i - 97;
        letters[index] -= 1;
    }

    for (int i: letters)
        if (i != 0)
            return false;
    return true;
}