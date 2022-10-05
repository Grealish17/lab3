#include <iostream>
#include "polygon.h"

using namespace PLGN;

int (*fptr[])(Polygon &)= {nullptr, D_Set_Data, D_Print};
const char *msgs[]={"0. Quit", "1. Set Data", "2. Print polygon"};
const int NMsgs = sizeof(msgs)/sizeof(msgs[0]);

int main() {
    Polygon polygon = Polygon();
    int rc;
    rc = dialog(msgs, NMsgs);
    while(rc)
    {
        if(!fptr[rc](polygon))
            break;
        rc = dialog(msgs, NMsgs);
    }
    std::cout << "That's all. Bye!\n";
    return 0;
}
