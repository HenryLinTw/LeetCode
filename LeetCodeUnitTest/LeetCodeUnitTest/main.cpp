//
//  main.cpp
//  LeetCodeUnitTest
//
//  Created by Henry Lin on 3/1/16.
//  Copyright © 2016 HengYi Lin. All rights reserved.
//

#include <iostream>

using namespace std;

    int bulbSwitch(int n) {
        if (n==0) return 0;
        bool status[n];
        fill_n(status, n, true);
        
        for (int i=1; i<n; i++)
        {
            for (int j=i; j<n; j+=(i+1))
            {
                status[j] = !status[j];
            }
        }
        
        int count = 0;
        for (int i=0; i<n; i++) {
            if (status[i] == true) count++;
        }
        
        return count;
        
    }
    

int main(int argc, const char * argv[]) {
    // insert code here...
    bulbSwitch(9999999);
    return 0;
}
