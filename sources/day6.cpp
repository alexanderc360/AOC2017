//
// Created by alex.cohen on 6/9/2022.
//
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<int> distribute(vector<int> bank);

bool repeat(const vector<int> &comp, const vector<vector<int>> &states);

void daySix() {
    ifstream input("day6.txt");
    vector<int> banks;
    vector<vector<int>> snapshots;
    vector<int> part2;

    int buff;
    while (input >> buff)
        banks.push_back(buff);

    snapshots.push_back(banks);

    for (int i = 0; i < 10000; ++i) {
        banks = distribute(banks);

        if (!repeat(banks, snapshots))
            snapshots.push_back(banks);
        else {
            part2 = banks;
            break;
        }
    }

    for (int i = 1; i < 10000; ++i) {
        banks = distribute(banks);
        if (banks == part2) {
            cout << i;
            break;
        }
    }
}

vector<int> distribute(vector<int> banks) {
    int max = banks[0], maxIndex = 0;

    for (int i = 0; i < banks.size(); ++i) {
        if (banks[i] >= max) {
            if (banks[i] == max) {
                if (i < maxIndex)
                    maxIndex = i;
            } else {
                max = banks[i];
                maxIndex = i;
            }
        }
    }

    int buff = max, index = maxIndex;
    banks[maxIndex] = 0;
    while (buff > 0) {
        index++;
        if (index == banks.size())
            index = 0;
        banks[index] += 1;
        buff--;
    }
    return banks;
}

bool repeat(const vector<int> &comp, const vector<vector<int>> &states) {
    bool valid = false;

    for (const auto &i: states)
        if (i == comp) {
            valid = true;
        }

    return valid;
}