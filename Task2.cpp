/*
 * Simple substitution cypher
*/
#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <bits/stdc++.h>
#include <cmath>
#include <stdbool.h>
#include <ctype.h>
using namespace std;
int main() {
    string n,k;
//  To make the loop work until the user exit the programme
    int counter = 0;
    while (counter == 0) {
        int num;
        cout << "1) Encryption" << endl << "2) Decryption" << endl << "3) Exit program" << endl
             << "Choose a number from 1 , 2 and 3: ";
        cin >> num;
        int b = 0;
        char list_1[26] = {'a', 'b', 'c', 'd', 'e', 'f',
                           'g', 'h', 'i', 'j', 'k', 'l',
                           'm', 'n', 'o', 'p', 'q', 'r',
                           's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        char list_2[26] = {'a', 'b', 'c', 'd', 'e', 'f',
                           'g', 'h', 'i', 'j', 'k', 'l',
                           'm', 'n', 'o', 'p', 'q', 'r',
                           's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        if (num == 1 || num == 2) {
            cout << "Enter a key with 5 unique letters:";
            cin >> k;
            cout << endl;
//          To check that the letters of the key are 5 unique letters
            for (int g=0;g<k.length();g++){
                for(int l=g+1 ;l< k.length() ; l++) {
                    if (k[g] == k[l] || k.length() != 5) {
                        cout << "Enter a key with 5 unique letters:";
                        cin >> k;
                        g=0;
                        cout << endl;
                    }
                }
            }
//          To make all letters in lowercase
            transform(k.begin(), k.end(), k.begin(), ::tolower);
            cout << "Enter your text:";
            cin.ignore();
            getline(cin, n);
            transform(n.begin(), n.end(), n.begin(), ::tolower);
            cout << endl;
            if (k.length() == 5) {
//              To rearrange the list_1 according to the key
                for (int i = 0, m = 0; i < 26; i++) {
                    if (list_1[i] == k[m]) {
                        for (int j = i; j > m; j--)
                            list_1[j] = list_1[j - 1];
                        list_1[b] = k[m];
                        m++;
                        b++;
                        i = 0;
                    }
                }
//              To encrypt
                if (num == 1) {
                    for (int i = 0, m = 0; i < n.length(); m++) {
                        if (n[i] == list_2[m]) {
                            n[i] = list_1[m];
                            i++;
                            m = 0;
                        }
                        if (n[i] == ' ')
                            n[i] = 6;
                    }
                    cout << "Encryption text:";
                    for (int i = 0; i < n.length(); i++)
                        cout << n[i];
                    cout << endl;
                }
//              To decrypt
                if (num == 2) {
                    for (int i = 0, m = 0; i < n.length(); m++) {
                        if (n[i] == list_1[m]) {
                            n[i] = list_2[m];
                            i++;
                            m = 0;
                        }
                        if (n[i] == ' ')
                            n[i] = 6;
                    }
                    cout << "Decryption text:";
                    for (int i = 0; i < n.length(); i++)
                        cout << n[i];
                    cout << endl;
                }
            }
        }
//      To exit the programme
        if (num == 3){
            cout << "Thanks for using my program";
            return 0;
        }
    }
}