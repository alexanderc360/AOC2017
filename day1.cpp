//
// Created by alex.cohen on 6/2/2022.
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string str;
    ifstream input("day1.txt");

    getline(input, str);

    //cout << str[0] - '0';

    int total = 0;
    int cur = 0, target = 0;

    for(int i = 0; i < str.size(); i++){
        target = i + str.size()/2;
        if(target > str.size())
            target -= str.size();

        if ((str[i] - '0') == (str[target] - '0')){
            total += (str[i] - '0');
        }
    }

//    if ((str[0] - '0') == (str[str.size() - 1] - '0'))
//        total += str[0] - '0';

    cout << total;
    input.close();
    return 0;
}
