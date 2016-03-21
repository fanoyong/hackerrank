#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstdlib>

using namespace std;

#define LL long long
#define DEBUG 0

const LL LIMIT = 100001;

void print (string a, LL i, string b, LL j, string c);

int main() {
    ifstream fin; 
    fin.open("input.morgan3");
    string a, b, c;
    int T;
    fin >> T;
    while (T--) {
        //char a[LIMIT], b[LIMIT], c[LIMIT];
        fin >> a >> b;
        const LL len_a = a.length() - 1;
        const LL len_b = b.length() - 1;
        char ca = '\0';
        char cb = '\0';
        string c = "";
        LL i=0, j=0;
        #if DEBUG
            cout << "len a/len b:" << len_a << "/" << len_b << endl;
        #endif
        while (i <= len_a || j <= len_b) {
            #if DEBUG
                cout << "i/j:" << i << "/" << j << endl;
            #endif
            if (i > len_a) {
                #if DEBUG
                    cout << "A reached end" << endl;
                    print (a,i,b,j,c);
                #endif
                c.append(b.substr(j,len_b-j+1));
                break;
            } else {
                ca = a.at(i);
            }
            if (j > len_b) {
                #if DEBUG
                    cout << "B reached end" << endl;
                    print (a,i,b,j,c);
                #endif
                c.append(a.substr(i,len_a-i+1));
                break;
            } else {
                cb = b.at(j);
            }
            #if DEBUG
                cout << "CA/CB:" << ca << "/" << cb << endl;
                print (a,i,b,j,c);
            #endif
            if (ca < cb) {
                #if DEBUG
                    cout << "Case 1" << endl;
                #endif
                c.push_back(ca);
                i++;
            } else if (ca > cb) {
                #if DEBUG
                    cout << "Case 2" << endl;
                #endif
                c.push_back(cb);
                j++;
            } else {
                string ar = a.substr(i,len_a-i+1);
                string br = b.substr(j,len_b-j+1);
                int cp = ar.compare(br);
                if (cp < 0) {
                    c.push_back(ca);
                    i++;
                } else if (cp > 0) {
                    c.push_back(cb);
                    j++;
                } else {
                    c.push_back(cb);
                    j++;
                }
            }
        }
        cout << c << endl;
    }
    return 0;
}

void print (string a, LL i, string b, LL j, string c)
{
    LL i2,j2;
    cout << "A:" << a.substr(i, a.length()-1-i) << endl;
    cout << "B:" << b.substr(j, b.length()-1-j) << endl;
    cout << "C:" << c << endl;
}

