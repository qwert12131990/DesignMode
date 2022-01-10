#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int add0 = 0;
        int add1 = 0;
        int carry = 0;
        int lena = 0;
        int lenb = 0;
        string rslt = "";

        while(lena < a.length() && lena < a.length()){
            int tmprslt;
            int tmpcurbit;
            int tmpcarry;
            add0 = a.at(lena) - '0';
            add1 = b.at(lenb) - '0';
            tmprslt = add0 + add1 + carry;
            tmpcurbit = tmprslt & 0b000001;
            tmpcarry  = tmprslt & 0b000010;
            carry = tmpcarry;
            rslt += ('0' + tmpcurbit);
            lena++;
            lenb++;
        }

        while(lena < a.length()){
            int tmprslt;
            int tmpcurbit;
            int tmpcarry;
            add0 = a.at(lena) - '0';
            tmprslt = add0 + carry;
            tmpcurbit = tmprslt & 0b000001;
            tmpcarry  = tmprslt & 0b000010;
            carry = tmpcarry;
            rslt += ('0' + tmpcurbit);
            lena++;
        }

        while(lenb < b.length()){
            int tmprslt;
            int tmpcurbit;
            int tmpcarry;
            add1 = b.at(lenb) - '0';
            tmprslt = add1 + carry;
            tmpcurbit = tmprslt & 0b000001;
            tmpcarry  = tmprslt & 0b000010;
            carry = tmpcarry;
            rslt += ('0' + tmpcurbit);
            lenb++;
        }

        if (carry == 1){
            rslt += ('0' + carry);
        }
        return rslt;
    }

};