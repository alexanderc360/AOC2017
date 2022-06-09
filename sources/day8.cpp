//
// Created by alex.cohen on 6/9/2022.
//

#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

void dayEight() {

    ifstream input("day8.txt");
    string str;

    map<string, int> regs;
    string step[7];

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


        for (const auto &i: step)
            cout << i << " ";
        cout << endl;
        regs[step[0]] = 0;
    }
}


map<string, int> part1(map<string, int> regs, string step[7]) {
    string focus = step[0], dependent = step[4], compare = step[5];
    bool increase = step[1] == "inc";
    int val = stoi(step[2]), compareNum = stoi(step[6]);

    if (regs.count(focus) == 0)
        


    if(increase){
        if (compare == ">")
            if
    }else{

    }

    return regs;
}