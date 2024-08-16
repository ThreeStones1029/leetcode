#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#include <string>
#include <vector>

int main() {
    string str;
    while(getline(cin, str)) {
        stringstream ss(str);
        string overall_string;
        vector<string> result;
        ss >> overall_string;
        int start = 0;
        int i;
        for (i = 0; i < overall_string.size(); i++) {
            if (overall_string[i] == ',') {
                string single_string(overall_string.begin() + start, overall_string.begin() + i);
                result.push_back(single_string);
                start = i + 1;
            }
        }
        for (i = overall_string.size() - 1; i >= 0; i--) {
            if (overall_string[i] == ','){
                string end_string(overall_string.begin() + i + 1, overall_string.end());
                result.push_back(end_string);
                break;
            }
        }
        // 如果没有','
        if (result.size() == 0) {
            result.push_back(overall_string);
        }
        std::sort(result.begin(), result.end());
        for (auto it = result.begin(); it != result.end(); ++it) {
            string single = *it;
            if (it != result.end() - 1) {
                cout << single << ",";
            }
            else {
                cout << single;
            }
            
        }
        cout << endl;
    }
}