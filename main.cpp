#include "VarTypes.hpp"
#include<string>
#include<iostream>
#include<fstream>

using namespace std;

int loop(u32 *p, string code);

int main(){
    
    u32 data[65536];

    u32 *p = data;

    fstream Source;
    Source.open("code.bfe", ios::in);

    if(!Source){
        cout << "Source Error";
        return 1;
    }

    string code = ".>+.>><.";

    string op;
    Source >> op;

    int i = 0;

    while(op[i]){
        
        //cout << op << endl;

        //cout << "Interpreting : " << op[i] << endl;

        switch(op[i]){
            case ' ':
                break;
            case '.':
                cout << (char)*(p);
                break;
            case '+':
                (*p)++;
                break;
            case '-':
                (*p)--;
                break;
            case '>':
                p++;
                break;
            case '<':
                p--;
                break;
            case '[':
                i += loop(p, op.substr(i));
                break;
            default:
                cout << "Error : " + op;

        }
        i++;
    }
}// 5bfde0

int loop(u32 *p, string code){
    u32 *back = p;
    int i = 1;
    bool flag = true;

    //cout << "Entering Loop" << endl;

    while(flag){
        //cout << "Interpreting : " << code[i] << endl;
        switch(code[i]){
            case ' ':
                break;
            case '.':
                cout << (char)*p;
                break;
            case '+':
                (*p)++;
                break;
            case '-':
                (*p)--;
                break;
            case '>':
                p++;
                break;
            case '<':
                p--;
                break;
            case '[':
                i += loop(p, code.substr(i));
                break;
            case ']':
                if(*p != 0){
                    i = 0;
                }else{
                    flag = false;
                }
                break;
            default:
                cout << "Error : ";

        }
        if(flag == false){
            break;
        }
        i++;
    }
    return i;
}