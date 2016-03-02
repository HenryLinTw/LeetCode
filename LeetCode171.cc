//
//  LeetCode171.cc
//  Created by Heng-Yi Lin on 2/29/16.
//
//  title: 171. Excel Sheet Column Number
//  Related to question Excel Sheet Column Title
//
//  Given a column title as appear in an Excel sheet, return its corresponding column number.
//
//  For example:
//  A -> 1
//  B -> 2
//  C -> 3
//  ...
//  Z -> 26
//  AA -> 27
//  AB -> 28
//
//  Analysis:
//  Only one char [A-Z] (e.g. A) = i * 26^0
//  two chars [A-Z]{2} (e.g. AA) = i * 26^1 + j * 26^0
//  three chars [A-Z]{3} (e.g. AAA) = i * 26^2 + j * 26^1 + k * 26^0
//  pattern: each char is i * 26^pos(DESC)
//
//  *technique: ASCII A-Z = 65-90
//  if you don't know, you may have to write switch helper function

class Solution {
public:
    int titleToNumber(string s) {
        int length = s.length();
        int sum = 0;
        
        // ascii A-Z = 65-90 -> (s[length-1] - 65) % 26 -> A=0,...,Z=25
        // pattern: A = i*26^0; AA = i*26^1 + j*26^0; AAA = i*26^2 + j*26^1 + k*26^0
        for(int i=0; i<length; i++) {
            sum += pow(26, length-i-1) * ((s[i]-65)%26 + 1);
        }
        return sum;
    }
    
    int whichChar(char c) {
        switch (c) {
            case 'A':
                return 1;
            case 'B':
                return 2;
            case 'C':
                return 3;
            case 'D':
                return 4;
            case 'E':
                return 5;
            case 'F':
                return 6;
            case 'G':
                return 7;
            case 'H':
                return 8;
            case 'I':
                return 9;
            case 'J':
                return 10;
            case 'K':
                return 11;
            case 'L':
                return 12;
            case 'M':
                return 13;
            case 'N':
                return 14;
            case 'O':
                return 15;
            case 'P':
                return 16;
            case 'Q':
                return 17;
            case 'R':
                return 18;
            case 'S':
                return 19;
            case 'T':
                return 20;
            case 'U':
                return 21;
            case 'V':
                return 22;
            case 'W':
                return 23;
            case 'X':
                return 24;
            case 'Y':
                return 25;
            case 'Z':
                return 26;
        }
    }
};
