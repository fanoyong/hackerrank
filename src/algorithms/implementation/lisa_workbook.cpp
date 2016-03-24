#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int div_ceil(int numerator, int denominator)
{
        std::div_t res = std::div(numerator, denominator);
        return res.rem ? (res.quot + 1) : res.quot;
}

int main() {
    int N, K;
    int DATA[100];
    int answer = 0;
    int cur_p = 1;
    cin >> N >> K;
    for (int i = 0; i<N; i++) {
        cin >> DATA[i];
        int new_p = div_ceil(DATA[i],K);
        for (int j = 0; j<new_p;j++){
            int cur_p2= cur_p + j;
            int lower_c = j*K + 1;
            int upper_c = (j+1)*K;
            if (upper_c > DATA[i]) {
                upper_c = DATA[i];
            }
            if (cur_p2 >= lower_c && cur_p2 <= upper_c) {
                answer++;
            }
        }
        cur_p += new_p;
    }
    cout << answer << endl;
    return 0;
}

