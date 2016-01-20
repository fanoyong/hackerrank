#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int N, i;
    long long data[200000];
    long long data2[200000];
    long long min = LLONG_MAX;
    cin >> N;
    for(i=0; i<N; i++) {
        cin >> data[i];
    }
    vector<long long> data_vector(data, data+N);
    sort(data_vector.begin(), data_vector.end());
    for(i=0; i<N-1; i++) {
        cout << data_vector[i+1] << "-" << data_vector[i] << endl;
        data2[i] = abs(data_vector[i+1] - data_vector[i]);
        if (data2[i] < min) {
            min = data2[i];
        }
    }
    for(i=0; i<N-1; i++) {
        if (data2[i] == min) {
            cout << data_vector[i] << " " << data_vector[i+1] << " ";
        }
    }
    return 0;
}
