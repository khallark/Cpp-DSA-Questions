#include <iostream>
#include <vector>
using namespace std;

/*

You are visiting a farm that has a single row
of fruit trees arranged from left to right.
The trees are represented by an integer array
fruits where fruits[i] is the type of fruit the
ith tree produces.


You want to collect as much fruit as possible.
However, the owner has some strict rules that
you must follow:
 - You only have two baskets, and each basket can only hold a single type of fruit.
   There is no limit on the amount of fruit each basket can hold.
 - Starting from any tree of your choice, you must pick exactly one fruit from every
   tree (including the start tree) while moving to the right. The picked fruits must fit
   in one of your baskets.
 - Once you reach a tree with fruit that cannot fit in your baskets, you must stop.


Given the integer array fruits, return the maximum number of fruits you can pick

*/

int totalFruit(vector<int>& fruits) {
    if(fruits.size() == 1) return 1; // If if there is only one tree, that one would obviously pick a single fruit only.

    int maxLen = 2;

    int type1 = -1, type2 = -1; // Keeping track of both types

    int i = 0;
    for(int j = 0; j < fruits.size(); j++) {

        if(type1 == -1 or type2 == -1) { // Basically assigns both variable a type.
            if(type1 == -1) type1 = fruits[j];
            else if(fruits[j] != type1) type2 = fruits[j];
        }
        
        else if(fruits[j] != type1 and fruits[j] != type2) { // If a new type arrives, the type which is just left to the new type,
        // is saved along with the new type, and the window length reduces.
            int savedType = fruits[j - 1];
            int k;
            for(k = j - 1; fruits[k] == savedType; k--) {}
            if(type1 == savedType) type2 = fruits[j];
            else type1 = fruits[j];
            i = k + 1;
        } maxLen = max(maxLen, j - i + 1); // keeping track of maximum fruits one could pick upto j.

    }

    return maxLen;
}

int main() {
    vector<int> fruits = {0,1,6,6,4,4,6};
    cout << totalFruit(fruits);
    return 0;
}