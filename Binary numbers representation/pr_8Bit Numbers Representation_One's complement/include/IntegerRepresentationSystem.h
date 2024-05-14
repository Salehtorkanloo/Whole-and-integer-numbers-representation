#ifndef INTEGERREPRESENTATIONSYSTEM_H_INCLUDED
#define INTEGERREPRESENTATIONSYSTEM_H_INCLUDED
#include<cinttypes>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<iterator>
using namespace std;
namespace Sali{

    namespace IntRepresentation{
            struct S8BitBinary{
                private:
                int value[8] = {0,0,0,0,0,0,0,0};
                public:
                static const char MAX_VALUE = 127;
                static const int8_t MIN_VALUE = -127;
                S8BitBinary(){}
                S8BitBinary(int value[8]){
                    copy(value, value+8, this->value);
                }

                static S8BitBinary OnesComplement(){
                    return S8BitBinary(new int[8]{1,1,1,1,1,1,1,1});
                }
                int8_t status = 0;

                S8BitBinary operator = (const S8BitBinary& b){
                    for(int i = 0 ; i < 8 ; ++i){
                        value[i] = b.value[i];
                    }
                    return *this;
                }
                int& operator[](const uint8_t& index){
                        return value[7 - index];
                }
                friend ostream& operator <<(ostream& i, const S8BitBinary& u){
                    for(int i = 0; i < 7; ++i){
                        cout << u.value[i];
                    }
                    return cout << u.value[7];
                }

            };
            void flan(S8BitBinary& a){

            }
            class RepresentationSystem{
            public:
            static S8BitBinary Rep(int numberToRepresent){


                S8BitBinary binaryValue = S8BitBinary();
                if(numberToRepresent > S8BitBinary::MAX_VALUE){
                   //Overflow
                   binaryValue.status = 1;
                   return binaryValue;
                }
                if(numberToRepresent < S8BitBinary::MIN_VALUE){
                    //Underflow
                    binaryValue.status = -1;
                    return binaryValue;
                }
                if(numberToRepresent == 0){
                    return S8BitBinary();
                }
                else if(numberToRepresent == -0){
                    return S8BitBinary().OnesComplement();
                };

                if(numberToRepresent < 0)
                    binaryValue = S8BitBinary::OnesComplement();

                int remainder = -1;
                while(remainder != 0){
                    int i = FloorToIntLog2( Abs(numberToRepresent) );

                    if(numberToRepresent < 0)
                        binaryValue[i] = 0;
                    else
                        binaryValue[i] = 1;

                    remainder = Abs( pow(2, i) - Abs(numberToRepresent) );
                    if(numberToRepresent > 0)
                        numberToRepresent = remainder;
                    else
                        numberToRepresent = -remainder;
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
