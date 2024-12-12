#include <iostream>
#include <bitset>
using namespace std;

int main() {
    // PROPERTY 1 :
    //- 2's compelent property,
    //- 2's comp(n) = -n.
   int n = 4832357;
   cout << ~n + 1 << endl; // 2's comp = Complement(n) + 1;


    // PROPERTY 2 :
    // n AND 2's comp(n) = 1.
    cout << (n & (~n + 1)) << endl;


    // PROPERTY 3 :
    // How to find the number of bits transformations to change a number A -> B.
    // the " ^ " operator will give the number bits in A and B, which are different.
    // the "__builtin_popcount" function will count the number of 1 bits in the result (A ^ B).
    cout << __builtin_popcount((11 ^ 15)) << endl;


    // PROPERTY 4 :
    // When you shift all the bits of a number 1 position to left, you basically multiply the number by 2,
    // When you shift all the bits of a number 1 position to right, you actually divide the number by 2.
    int num = 124;
    cout << (num >> 1) << endl << (num << 1) << endl; 


    // PROPERTY 5 :
    // To extract the i-th bit of a number.
    // Suppose we have a number of binary 11001001, and we have to output the 4rd bit of this number.
    // We take 1 << 3 (= 1000) and then do 11001001
    //                                        &1000
    //                                    =    1000
    num = 201; // 11001001
    cout << ((num & (1 << 4)) >> 4) << endl;


    // PROPERTY 6 :
    // To unset the i-th bit.
    // Suppose we have 11001001 and we want to make it 11000001.
    cout << "Number -\t" << bitset<8>(num) << endl;
    cout << "4th bit unset - " << bitset<8>(num & ~(1 << 3)) << endl;
    return 0;
}