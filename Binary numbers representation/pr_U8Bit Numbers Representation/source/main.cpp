#include<iostream>
#include<IntegerRepresentationSystem.h>
using namespace std;
using namespace Sali::IntRepresentation;
int main(char** args)
{
    cout << "Sali 1403/2/22" << endl;
    cout << "whole numbers representation with unsigned 8 bit range" << endl;

    while(true){
        cout << "please enter a number in the range [0,255]" << endl;


        int a = 0;
        cin >> a;
        Unsigned8BitBinary binaryValue = RepresentationSystem::Rep(a);
        if(binaryValue.status == 1 || binaryValue.status == -1){
            //1 : overflow, -1 : underflow
            cout << "Sorry,"
                    "The minimum value of the uint8 is: 0 and maximum"
                    "is 2^8 - 1 which is 255" << endl << endl;
            continue;
        }

        cout << "The representation of the number " << a << " in binary is:" << endl;
        cout << binaryValue << "B" << endl;;
        cout << "Because: " << endl;
        for(int i = 0; i < 8; ++i){
            cout << "2^" << (7-i) << "*"
            << binaryValue[7-i];
            if(i < 7)
                cout << " + ";

        }
        cout << " = " << a;
        cout << endl << endl;
    }
}
