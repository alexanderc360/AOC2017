//
// Created by alex.cohen on 6/8/2022.
//
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void dayFive() {
    int i;
    ifstream input("day5.txt");
    vector<int> steps;

    while (input >> i)
        steps.push_back(i);

    int index = 0, buff, count = 0, offset;

    while (index < steps.size()) {
        buff = index;
        offset = steps[index];
        index += offset;
        if (offset >= 3)
            steps[buff]--;
        else
            steps[buff]++;
        count++;
    }

    cout << count;
}