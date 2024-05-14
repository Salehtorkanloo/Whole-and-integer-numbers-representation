#include<iostream>
#include<IntegerRepresentationSystem.h>
using namespace std;
using namespace Sali::IntRepresentation;
int main(char** args)
{

    cout << "Sali 1403/2/25" << endl;
    cout << "whole numbers representation with signed 8 bit range in one's complement" << endl;

    while(true){
        cout << "please enter a number in the range [-127,+127]" << endl;


        int a = 0;
        cin >> a;
        S8BitBinary binaryValue = RepresentationSystem::Rep(a);
        if(binaryValue.status == 1 || binaryValue.status == -1){
            //1 : overflow, -1 : underflow
            cout << "Sorry,"
                    "The minimum value of the int8 is: -(2^7 - 1) and maximum"
                    "is 2^7 - 1 which are -127 and +127 respectively" << endl << endl;
            continue;
        }

        cout << "The representation of the number " << a;
        if(a >= 0)
            cout << " in binary is:" << endl;
        else
            cout << " in one's complement scheme is:" << endl;

        cout << binaryValue << "B" << endl;
    }
}
