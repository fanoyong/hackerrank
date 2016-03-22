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

void print (string a, LL i, string b, LL j, string c);

int main() {
    // ifstream fin; 
    // fin.open("input.morgan3");
    string a, b, c;
    int T;
    cin >> T;
    while (T--) {
        //char a[LIMIT], b[LIMIT], c[LIMIT];
        cin >> a >> b;
        a.push_back('[');
        b.push_back('[');
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
                print (a,i,b,j,c);
            #endif
            if (i > len_a) {
                #if DEBUG
                    cout << "A reached end" << endl;
                #endif
                c.append(b.substr(j,len_b-j+1));
                break;
            } else {
                ca = a.at(i);
            }
            if (j > len_b) {
                #if DEBUG
                    cout << "B reached end" << endl;
                #endif
                c.append(a.substr(i,len_a-i+1));
                break;
            } else {
                cb = b.at(j);
            }
            #if DEBUG
                cout << "CA/CB:" << ca << "/" << cb << endl;
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
                LL i2 = i;
                LL j2 = j;
                char ca2 = a.at(i2);
                char cb2 = b.at(j2);
                #if DEBUG
                    cout << "Case 3 ca2:" << ca2 << "/cb2:" << cb2 << endl;
                #endif
                int flag = 1;
                while (ca2 == cb2) {
                    i2++;
                    j2++;
                    if (i2 > len_a) {
                        flag <<= 1;
                    }
                    if (j2 > len_b) {
                        flag <<= 1;
                    }
                    if (flag > 1) {
                        break;
                    }                    
                    ca2 = a.at(i2);
                    cb2 = b.at(j2);
                    #if DEBUG
                        cout << "i2:" << i2 << " j2:" << j2  << " ca2:" << ca2 << " cb2:" << cb2 << endl;
                    #endif
                }
                if (flag != 4) {
                    if (ca2 < cb2) {
                    #if DEBUG
                        cout << "c before:" << c << endl;
                    #endif
                        c += a.substr(i, (i2-i));
                    #if DEBUG
                        cout << "c after:" << c << endl;
                    #endif
                        i = i2;
                    } else {
                        c += b.substr(j, (j2-j));
                        j = j2;
                    }
                } else {
                    c.push_back(cb);
                    j++;
                }
            }
        }
        cout << c.substr(0, len_a+len_b) << endl;
    }
    return 0;
}

void print (string a, LL i, string b, LL j, string c)
{
    LL i2,j2;
    cout << "A:" << a.substr(i, a.length()-i) << endl;
    cout << "B:" << b.substr(j, b.length()-j) << endl;
    cout << "C:" << c << endl;
}

