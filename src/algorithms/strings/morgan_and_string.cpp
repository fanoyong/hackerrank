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
    fin.open("input.morgan");
    int T;
    fin >> T;
    while (T--) {
        //char a[LIMIT], b[LIMIT], c[LIMIT];
        string a,b,c;
        fin >> a >> b;
        const LL len_a = a.length() - 1;
        const LL len_b = b.length() - 1;
        char ca;
        char cb;
        //const LL len_a = strlen(a) - 1;
        //const LL len_b = strlen(b) - 1;
        #if DEBUG
            cout << "A:" << len_a << " B:" << len_b << endl;
        #endif
        LL i = 0;
        LL j = 0;
        LL k = 0;
        while (i <= len_a || j <= len_b) {
            #if DEBUG
                print(a,i,b,j,c);
            #endif
            if (i <=len_a) ca = a.at(i);
            if (j <=len_b) cb = b.at(j);
            if (i >= len_a + 1) {
                #if DEBUG
                        cout << "append A" << endl;
                #endif
                while (j<=len_b) {
                    c.push_back(b.at(j));
                    //c[k++] = b[j];   
                    j++;
                }
            } else if (j >= len_b + 1) {
                #if DEBUG
                        cout << "append A" << endl;
                #endif
                while (i<=len_a) {
                    // c[k++] = b[i];
                    c.push_back(a.at(i));
                    i++;
                }
            } else if (ca < cb) {
                c.push_back(ca);
                //c[k++] = ca;
                i++;
            } else if (ca > cb) {
                c.push_back(cb);
                //c[k++] = cb;
                j++;
            } else if (ca == cb) {
                #if DEBUG
                    cout << "ca == cb i/j:" << i << "/" << j << endl;
                #endif
                LL i2 = i;
                if (i2 >= len_a) {
                    #if DEBUG
                        cout << "just increase j" << endl;
                    #endif
                    c.push_back(cb);
                    j++;
                    continue;
                }
                char next_a = a.at(i2);
                LL j2 = j;
                if (j2 >= len_b) {
                    #if DEBUG
                        cout << "just increase i" << endl;
                    #endif
                    c.push_back(ca);
                    i++;
                    continue;
                }
                char next_b = b.at(j2);
                #if DEBUG
                    cout << "check next small char" <<  endl;
                #endif
                while (i2<=len_a && next_a >= ca) {
                    next_a = a.at(i2++);
                }
                i2--;
                while (j2<=len_b && next_b >= cb) {
                    next_b = b.at(j2++);
                }
                j2--;
                int ilen = i2 - i;
                int jlen = j2 - j;
                #if DEBUG
                    cout << "next a:" << next_a << "/" << ilen << " next_b:" << next_b << "/" << jlen << endl;
                #endif
                if (jlen < ilen) {
                    c.push_back(cb);
                    j++;
                } else if (jlen > ilen) {
                    c.push_back(ca);
                    i++;
                } else {
                    if (next_a < next_b) {
                        c.push_back(ca);
                        i++;
                        continue;
                    } else if (next_b < next_a) {
                        c.push_back(cb);
                        j++;
                        continue;
                    }
                    #if DEBUG
                    cout << "i2 & j2 is also same" << endl;
                    #endif
                    LL i3 = i2+1;
                    if (i3 >= len_a) {
                        #if DEBUG
                            cout << "just increase j2" << endl;
                        #endif
                        c.push_back(cb);
                        j++;
                        continue;
                    }
                    char next_a2 = a.at(i3);
                    LL j3 = j2+1;
                    if (j3 >= len_b) {
                        #if DEBUG
                            cout << "just increase i2" << endl;
                        #endif
                        c.push_back(ca);
                        i++;
                        continue;
                    }
                    char next_b2 = b.at(j3);
                    while (i3<=len_a && next_a2 >= ca) {
                        next_a2 = a.at(i3++);
                    }
                    while (j3<=len_b && next_b2 >= cb) {
                        next_b2 = b.at(j3++);
                    }
                    int ilen2 = i3 - i2;
                    int jlen2 = j3 - j2;
                    #if DEBUG
                        cout << "next a2:" << next_a2 << "/" << ilen2 << " next_b2:" << next_b2 << "/" << jlen2 << endl;
                    #endif
                    if (ilen2 > jlen2) {
                        c.push_back(cb);
                        j++;
                    } else {
                        c.push_back(ca);
                        i++;
                    }
                }
            }
        }
        //c[k] = '\0';
        #if DEBUG
            cout << "C length:" << c.length() << endl;
        #endif
        cout << c << endl;
    }
    return 0;
}

void print (string a, LL i, string b, LL j, string c)
{
    LL i2,j2;
    cout << "A:";
    for(i2=i;i2<a.length();i2++){
        cout << a.at(i2);
    }
    cout << endl;
    cout << "B:";
    for(j2=j;j2<b.length();j2++){
        cout << b.at(j2);
    }
    cout << endl;
    cout << "C:" <<  c << endl;
}

