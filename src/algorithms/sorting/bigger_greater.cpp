#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    string input;
    cin >> N;
    while (N--) {
        cin >> input;
        int k = input.length()-2;
        for (; k>=0 ;k--) {
            if(input[k] < input[k+1]) {
                break;
            }
        }
        if (k<0) {
            cout << "no answer" << endl;
            continue;
        }
        int l = input.length()-1;
        for(;l>k;l--) {
            if (input[k] < input[l]) {
                break;
            }
        }
        char t = input[k];
        input[k] = input[l];
        input[l] = t;
        int start = k+1;
        int end = input.length()-1;
        while(start < end) {
            char temp = input[start];
            input[start] = input[end];
            input[end] = temp;
            start++;
            end--;
        }
        cout << input << endl;
    }
    return 0;
}

