//
// Created by alex.cohen on 6/8/2022.
//

#include "day3.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

vector<vector<int>> boardGen(int size);

void dayThree() {
    vector<vector<int>> board;

    vector<int> buff;
    buff.push_back(0);
    board.push_back(buff);

    for (const auto &i: board) {
        for (auto j: i)
            cout << j;
        cout << endl;
    }
}


vector<vector<int>> boardGen(int size){

    return {};
}