#include "QLSP.h"
#include <iostream>

using namespace std;



int main(){
    int luaChon;
    do{
        cout<<"1. Quan ly san pham"<<endl;
        cin >> luaChon;
        switch(luaChon){
            case 1:
                QLSPmenu();
                break;
            case 0:
                cout<<"Ket thuc chuong trinh"<<endl;
                break;
            default:
                cout<<"Lua chon khong hop le"<<endl;
                break;

        }
    }while(luaChon != 0);
}