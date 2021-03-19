#include <iostream>
#include <fstream>
#include <string.h>
#include "sculptor.h"

using namespace std;

int main()
{

    sculptor cubo(50,60,50);
    cubo.setColor(0.1,0.1,0.1,0.1);
    cubo.putBox(4,9,8,29,7,16);
    cubo.writeOFF((char*)"cubo.off");     
    return  0;
}
