#include<bits/stdc++.h>
using namespace std;

const vector<int> IP = {
    58, 50, 42, 34, 26, 18, 10, 2,
    60, 52, 44, 36, 28, 20, 12, 4,
    62, 54, 46, 38, 30, 22, 14, 6,
    64, 56, 48, 40, 32, 24, 16, 8,
    57, 49, 41, 33, 25, 17, 9, 1,
    59, 51, 43, 35, 27, 19, 11, 3,
    61, 53, 45, 37, 29, 21, 13, 5,
    63, 55, 47, 39, 31, 23, 15, 7
};

const vector<int> FP = {
    40, 8, 48, 16, 56, 24, 64, 32,
    39, 7, 47, 15, 55, 23, 63, 31,
    38, 6, 46, 14, 54, 22, 62, 30,
    37, 5, 45, 13, 53, 21, 61, 29,
    36, 4, 44, 12, 52, 20, 60, 28,
    35, 3, 43, 11, 51, 19, 59, 27,
    34, 2, 42, 10, 50, 18, 58, 26,
    33, 1, 41, 9, 49, 17, 57, 25
};


string convertToBin(string str){
    string res="";
    for(auto it:str){
        res+=bitset<8>(it).to_string();
    }
    cout<<"Binary String: "<<res<<endl;
    
    if (res.size() > 64) {
        return res.substr(0, 64);
    } else if (res.size() < 64) {
        return res + string(64 - res.size(), '0');
    }
    return res;
}


int main() {
    string input;
    cout << "Enter an alphanumeric string (max 8 characters): ";
    cin >> input;

    string binaryInput = convertToBin(input);
    cout << "Binary Input: " << binaryInput << endl;

    string initialPermutation = "";
    for(auto i:IP){
        initialPermutation+=binaryInput[i-1];
    }
    cout << "After Initial Permutation: " << initialPermutation << endl;

    string finalPermutation="";
    for(auto i:FP){
        finalPermutation+=initialPermutation[i-1];
    }
    cout << "After Final Permutation: " << finalPermutation << endl;

    if (finalPermutation == binaryInput) {
        cout << "Verification Successful: Final Permutation (FP) is the inverse of Initial Permutation (IP)." << endl;
    } else {
        cout << "Verification Failed: FP is NOT the inverse of IP." << endl;
    }

    return 0;
}
