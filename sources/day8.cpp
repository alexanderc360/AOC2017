//
// Created by alex.cohen on 6/9/2022.
//

#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<string, int> editRegister(map<string, int> regs, string step[7]);

void dayEight() {

    ifstream input("day8.txt");
    string str;

    map<string, int> regs;
    string step[7];
    int max = 0;

    while (getline(input, str)) {
        step[0] = str.substr(0, str.find(' '));
        str = str.substr(str.find(' ') + 1);

        step[1] = str.substr(0, str.find(' '));
        str = str.substr(str.find(' ') + 1);

        step[2] = str.substr(0, str.find(' '));
        str = str.substr(str.find(' ') + 1);

        step[3] = str.substr(0, str.find(' '));
        str = str.substr(str.find(' ') + 1);

        step[4] = str.substr(0, str.find(' '));
        str = str.substr(str.find(' ') + 1);

        step[5] = str.substr(0, str.find(' '));
        str = str.substr(str.find(' ') + 1);

        step[6] = str.substr(0, str.find(' '));
        str = str.substr(str.find(' ') + 1);

        for (const auto &i: regs)
            if (i.second > max)
                max = i.second;

        regs = editRegister(regs, step);
    }



    cout << max;
}

map<string, int> editRegister(map<string, int> regs, string step[7]) {
    string focus = step[0], dependent = step[4], compare = step[5];
    bool increase = step[1] == "inc";
    int val = stoi(step[2]), compareNum = stoi(step[6]);

    if (regs.count(focus) == 0)
        regs[focus] = 0;
    if (regs.count(dependent) == 0)
        regs[dependent] = 0;


    if (increase) {
        if (compare == ">") {
            if (regs[dependent] > compareNum)
                regs[focus] += val;
        } else if (compare == "<") {
            if (regs[dependent] < compareNum)
                regs[focus] += val;
        } else if (compare == ">=") {
            if (regs[dependent] >= compareNum)
                regs[focus] += val;
        } else if (compare == "<=") {
            if (regs[dependent] <= compareNum)
                regs[focus] += val;
        } else if (compare == "==") {
            if (regs[dependent] == compareNum)
                regs[focus] += val;
        } else if (compare == "!=") {
            if (regs[dependent] != compareNum)
                regs[focus] += val;
        }
    } else {
        if (compare == ">") {
            if (regs[dependent] > compareNum)
                regs[focus] -= val;
        } else if (compare == "<") {
            if (regs[dependent] < compareNum)
                regs[focus] -= val;
        } else if (compare == ">=") {
            if (regs[dependent] >= compareNum)
                regs[focus] -= val;
        } else if (compare == "<=") {
            if (regs[dependent] <= compareNum)
                regs[focus] -= val;
        } else if (compare == "==") {
            if (regs[dependent] == compareNum)
                regs[focus] -= val;
        } else if (compare == "!=") {
            if (regs[dependent] != compareNum)
                regs[focus] -= val;
        }
    }

    return regs;
}