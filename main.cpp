#include <iostream>
#include "polygon.h"

int dialog(const char *msgs[], int);
int D_Set_Data(PLGN::Polygon &);
int D_Print(PLGN::Polygon &);
int D_Center_Of_Gravity(PLGN::Polygon &);
int D_Add_Vertex(PLGN::Polygon &);
int D_Rotate_On_Angle(PLGN::Polygon &);
int D_Parallel_Transfer(PLGN::Polygon &);
int D_Get_Coordinates(PLGN::Polygon &);

using namespace PLGN;

int (*fptr[])(Polygon &)= {nullptr, D_Set_Data, D_Print, D_Add_Vertex, D_Get_Coordinates, D_Center_Of_Gravity, D_Rotate_On_Angle, D_Parallel_Transfer};
const char *msgs[]={"0. Quit", "1. Set Data", "2. Print polygon","3. Add vertex" , "4. Get coordinates of vertex by number","5. Center of gravity", "6. Rotate on angle", "7. Parallel transfer on the vector"};
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
