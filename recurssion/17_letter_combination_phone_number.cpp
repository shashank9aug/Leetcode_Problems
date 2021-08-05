/*
    we have all the phone keypad numbers from which we can input any set of string as i/p

    we have to return all the possible set of strings which can be generate corresponding to 
    input set of numbers 

    eg : 
        23   2-> ABC   3->DEF
        {
            AD,AE,AF
            BD,BE,BF
            CD,CE,CF
        }

        666  6->MNO  => will give MOM as suggestion in mobile keypad
        {
            MMM,MNO,MOM,....
            Enter input string : 666
MMM
MMN
MMO
MNM
MNN
MNO
    MOM
MON
MOO
NMM
NMN
NMO
NNM
NNN
NNO
NOM
NON
NOO
OMM
OMN
OMO
ONM
ONN
ONO
OOM
OON
OOO
        }

    Approach : 
    we have choice for every single letter 
    so we can take or leave it's our decision 
    choice + Decision => Recurssive Tree     
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//keypad Setup :
char keyPair[][10] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void generateString(char *ip, char *op, int i, int j)
{
    //Base case:
    if (ip[i] == '\0')
    {
        op[j] = '\0';
        cout << op << "\n";
        return;
    }

    //rec case :
    int digit = ip[i] - '0';

    //If digit will be 1 or 0 skip that digit in input:
    if(digit==1 or digit==0){
       generateString(ip,op,i+1,j); 
    }

    for (int k = 0; keyPair[digit][k] != '\0'; k++)
    {
        op[j] = keyPair[digit][k];

        //fill the remaining part
        generateString(ip, op, i + 1, j + 1);
    }

    return;
}

/*
Enter input string : 23
AD
AE
AF
BD
BE
BF
CD
CE
CF

*/
int main()
{
    char ip[100];
    cout << "Enter input string : ";
    cin >> ip;

    char op[100];

    generateString(ip, op, 0, 0);

    return 0;
}