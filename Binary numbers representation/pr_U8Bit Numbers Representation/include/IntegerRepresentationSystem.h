#ifndef INTEGERREPRESENTATIONSYSTEM_H_INCLUDED
#define INTEGERREPRESENTATIONSYSTEM_H_INCLUDED
#include<cinttypes>
#include<iostream>
#include<cmath>
using namespace std;
namespace Sali{

    namespace IntRepresentation{
            struct Unsigned8BitBinary{
                private:
                int value[8] = {0,0,0,0,0,0,0,0};
                public:
                int8_t status = 0;
                Unsigned8BitBinary operator = (Unsigned8BitBinary& b){
                    for(int i = 0 ; i < 8 ; ++i){
                        value[i] = b.value[i];
                    }
                    return *this;
                }
                int& operator[](const uint8_t& index){
                        return value[7 - index];
                }
                friend ostream& operator <<(ostream& i, const Unsigned8BitBinary& u){
                    for(int i = 0; i < 7; ++i){
                        cout << u.value[i];
                    }
                    return cout << u.value[7];
                }

            };
            class RepresentationSystem{
            public:
            static Unsigned8BitBinary Rep(int numberToRepresent){
                Unsigned8BitBinary binaryValue;
                if(numberToRepresent > 255){
                   //Overflow
                   binaryValue.status = 1;
                   return binaryValue;
                }
                if(numberToRepresent < 0){
                    //Underflow
                    binaryValue.status = -1;
                    return binaryValue;
                }
                if(numberToRepresent == 0){
                    return Unsigned8BitBinary();
                }

                int remainder = -1;
                while(remainder != 0){
                    int i = FloorToIntLog2(numberToRepresent);
                    binaryValue[i] = 1;
                    remainder = Abs( pow(2, i) - numberToRepresent);
                    numberToRepresent = remainder;
                }
                return binaryValue;


            }

            private:
                static int FloorToIntLog2(int a){
                    uint8_t power = 0;
                    while(pow(2,power) <= a){
                        ++power;
                    }
                    return --power;

                }
                static int Abs(int a){
                    if(a >= 0){
                        return a;
                    }
                    return -a;
                }
        };

    }

}


#endif // INTEGERREPRESENTATIONSYSTEM_H_INCLUDED
