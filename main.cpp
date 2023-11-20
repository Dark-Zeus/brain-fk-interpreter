/****************************************************************
 * Name : Brain F**k Interpreter
 * Author : Dark-Zeus
 * Github : https://github.com/Dark-Zeus/brain-fk-interpreter
 * Date : 2023/11/20
 * Version : 1.1
 * 
*****************************************************************/

#include "VarTypes.hpp"
#include<string>
#include<iostream>
#include<fstream>

/* Define Symbols to Use*/

#define PRINT_ASCII '.'
#define PRINT_INT '_'
#define INPUT ','
#define ADD '+'
#define SUBSTRACT '-'
#define LEFT '<'
#define RIGHT '>'
#define LOOP_START '['
#define LOOP_END ']'

using namespace std;

int loop(u32 *&p, string code);
void interpreter(u32 *&p, char code);

int main(int argc, char* argv[]) {
    if(argc < 2) {
        cout << "Please provide a file name." << endl;
        return 1;
    }

    string file_name = argv[1];
    
    u32 data[65536];

    u32 *pointer = data;

    fstream Source;
    Source.open(file_name, ios::in);

    if(!Source){
        cout << "Source Error";
        return 1;
    }

    string source_code;
    Source >> source_code;

    int i = 0;

    while(source_code[i]){
        switch(source_code[i]){
            case LOOP_START:
                i += loop(pointer, source_code.substr(i));
                break;
            default:
                interpreter(pointer, source_code[i]);
        }
        i++;
    }
}// 5bfde0

int loop(u32 *&pointer, string loop_code){
    int i = 1;
    bool flag = true;

    //cout << "Entering Loop" << endl;

    while(flag){
        switch(loop_code[i]){
            case LOOP_END:
                if(*pointer != 0){
                    i = 0;
                }else{
                    flag = false;
                }
                break;
            case LOOP_START:
                i += loop(pointer, loop_code.substr(i));
                break;
            default:
                interpreter(pointer, loop_code[i]);

        }
        if(flag == false){
            break;
        }
        i++;
    }
    return i;
}

void interpreter(u32 *&pointer, char operation){
    //cout << "Interpreting : " << code << endl;
    switch(operation){
        case ' ':
            break;
        case PRINT_ASCII:
            cout << (char)*pointer;
            break;
        case PRINT_INT:
            cout << *pointer;
            break;
        case INPUT:
            //cout << "Input : ";
            cin >> *pointer;
            break;
        case ADD:
            (*pointer)++;
            break;
        case SUBSTRACT:
            (*pointer)--;
            break;
        case RIGHT:
            pointer++;
            break;
        case LEFT:
            pointer--;
            break;
        default:
            cout << "Error : " << operation << " is not a valid oparation" << endl;

    }
}