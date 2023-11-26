#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    char choice;

    do{
        cout << "1.) Decimal to Binary" << endl << "2.) Binary to Decimal" << endl << "Please choose: ";
        cin >> choice;

        switch(choice){
            
            case '1':{
                /*converts decimal to binary*/
                int n, decimal;
                string remainder;
                cout << "Enter decimal: ";
                cin >> decimal;

                n = decimal;

                do{
                    /*keeps track of the remainder*/
                    remainder += to_string(n % 2);
                    n = n / 2;
                    
                } while(n != 0);

                /*reverses the remainder to get binary*/
                reverse(remainder.begin(), remainder.end());

                cout << decimal << " in binary is: " << remainder;
                break;}

            case '2':{
                /*convert binary to decimal*/
                int binary, powOf, length, decimal, zeroAscii;
                string binaryToString;

                /*asks user for binary input*/
                cout << "Enter binary: ";
                cin >> binary;

                //converts binary input to string to make it indexable
                binaryToString = to_string(binary);

                /*get length of binary input*/
                length = binaryToString.length();

                /*converts binary to char* to do ascii*/
                const char* charArray = binaryToString.c_str();

                /*if power starts with 4, it must start with 3. So we subtract 1*/
                powOf = length - 1;

                /*prevents buffer error*/
                zeroAscii = '0';
                
                for(int i = 0; i < length; i++){
                    /*get current value of the index of binary input*/
                    int current = charArray[i] - zeroAscii;

                    /*formula to convert binary to decimal*/
                    decimal +=  current * pow(2, powOf);
                    powOf -= 1;
                }

                cout << binary << " to decimal is: " << decimal;

                break;}
            
            default:{
                cout << endl << "Invalid input" << endl << endl;
                }
            }
    /*reprompt the user for correct input*/
    }while(choice != '1' && choice != '2');

}