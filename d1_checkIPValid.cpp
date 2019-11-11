#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <regex>
#include <iostream>

using namespace std;

int string2int(string x){
    size_t pos;
    int a = stoi(x, &pos, 10);
    return a;
}

bool valid(const smatch &m) {
    if((string2int(m[1]) <=255) && (string2int(m[3]) <=255) 
        && (string2int(m[5]) <=255)&&(string2int(m[7]) <=255)) {
        return true;
    }
    return false;
}

int main(int argc, char** argv) {
    fstream fp("IP_testcase");

    vector<string> words;
    vector<string> result;
    string line;
    while(getline(fp,line)) {
        words.push_back(line);
    }

    string pattern = "^(\\d{1,3})([-.])(\\d{1,3})([-.])(\\d{1,3})([-.])(\\d{1,3})$";
    regex r(pattern);
    vector<string>::iterator it;
    for(it = words.begin();it!=words.end();it++) {
        for(sregex_iterator sit((*it).begin(),(*it).end(),r),end_it; sit != end_it; ++sit) {
            if(valid(*sit)) {
                result.push_back(*it);
            }
        }
    }

    for(it = result.begin();it!=result.end();it++) {
        cout << *it <<" is ok" << endl;
    }

    return 0;
}