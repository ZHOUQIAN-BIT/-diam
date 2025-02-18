#include <iostream>

void triggerSegfault(){
    int* p = nullptr;
    *p = 0;
}

void callFault(){triggerSegfault();}

void startFault(){callFault();}

int main(){

    startFault();

    return 0;

}

