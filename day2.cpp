//
// Created by alex.cohen on 6/2/2022.
//
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


int diff(const string &);

int prod(const string &);

void dayTwo() {
    string str;
    int total = 0;
    ifstream input("day2.txt");

    while (getline(input, str))
        total += prod(str);

     cout << total;
}

int diff(const string &row) {
    stringstream buff(row);

    int num, max = 0, min = 0;
    while (buff >> num) {
        if (min == 0)
            min = num;
        if (num > max)
            max = num;
        if (num < min)
            min = num;
    }
    return max - min;
}

int prod(const string &row) {
    int count = 0, i;
    stringstream buff(row);
    while (buff >> i)
        count++;

    stringstream s(row);
    int nums[count];
    for (auto j = 0; j < count; j++)
        s >> nums[j];

    for (int a = 0; a < count; a++)
        for (int b = 0; b < count; b++)
            if (a != b)
                if (nums[a] % nums[b] == 0) {
                    return nums[a] / nums[b];
                }
    return 0;
}