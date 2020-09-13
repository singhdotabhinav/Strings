/*
Given a string containing of ‘0’, ‘1’ and ‘?’ wildcard characters, generate all binary strings that can be formed by replacing each wildcard character by ‘0’ or ‘1’.
Example :

Input str = "1??0?101"
Output: 
        10000101
        10001101
        10100101
        10101101
        11000101
        11001101
        11100101
        11101101
*/

//Recursivve approach

#include <iostream>
using namespace std;



void print(string str, int index){

    if(index==str.size()){
        cout<<str<<endl;
        return;
    }
    if(str[index]=='?'){
        str[index]='0';
        print(str,index+1);

        str[index]='1';
        print(str,index+1);
    }
    else
        print(str,index+1);
}
int main()
{
    string str = "1??0?101";

    print(str, 0);

    return 0;
}
