//
//  LeetCode319.cc
//  Created by Heng-Yi Lin on 3/1/16.
//
//  title: 319. Bulb Switcher
//  There are n bulbs that are initially off. You first turn on all the bulbs. Then, you turn off every
//  second bulb. On the third round, you toggle every third bulb (turning on if it's off or turning off
//  if it's on). For the ith round, you toggle every i bulb. For the nth round, you only toggle the
//  last bulb. Find how many bulbs are on after n rounds.
//
//  Example:
//
//  Given n = 3.
//
//  At first, the three bulbs are [off, off, off].
//  After first round, the three bulbs are [on, on, on].
//  After second round, the three bulbs are [on, off, on].
//  After third round, the three bulbs are [on, off, off].
//  So you should return 1, because there is only one bulb is on.
//
//  Analysis:
//  A bulb which is switched for even times will eventually be off; a bulb which is
//  switched for odd times will eventually be on.
//
//  Every bulb will be switched for its number of factors times.
//  e.g. 3 = 1*3 -> even times -> off
//  e.g. 9 = 1*3*9 -> odd times -> on
//  From the above example, we can then observe that only when the number can be square rooted, it will
//  be switched for odd times. Therefore,the answer is the count of numbers which can be square rooted.
//
//  As far as we know, to find the count of numbers can be square rooted which is less than or equals
//  to a number, we simply need to square root the number and get the floor of the result.
//  e.g. sqrt(16) -> 4 -> 1,4,9,16
//  e.g. sqrt(17) -> 4 -> 1,4,9,16


class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};