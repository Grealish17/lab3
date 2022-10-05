#include "polygon.h"

using namespace PLGN;

int dialog(const char *msgs[], int K){
    std::string errmsg;
    int rc;
    int n;
    do{
        std::cout << errmsg << "\n";
        errmsg = "You are wrong. Repeat, please!";
        std::cout << "===============\n";
        std::cout << "This is Polygon\n";
        std::cout << "===============\n";
        for(int i=0; i<K; ++i)
        {
            std::cout << msgs[i] << "\n";
        }
        std::cout << "\n";
        std::cout << "Make your choice: ";
        n = scanf("%d", &rc);
        scanf("%*[^\n]");
        scanf("%*c");
        if(n == 0)
        {
            rc = 0;
        }
    } while (rc<0 || rc >= K);
    return rc;
}


int D_Set_Data(PLGN::Polygon & polygon){
    int n;
    std::cout << "Enter number of vertex: ";
    std::cin >> n;
    Vertex vertex[N_MAX];
    for(int i(0); i<n; ++i){
        std::cout << i+1 << " vertex: " << "\n";
        std::cout << "Enter first coordinate, x = : ";
        std::cin >> vertex[i].x;
        std::cout << "Enter second coordinate, y = : ";
        std::cin >> vertex[i].y;
    }
    try{
        polygon.set_n(n);
    }
    catch(std::invalid_argument& exception){
        std::cout << "Number of vertex mast be >= 0" << "\n";
    }
    polygon.set_coordinates(vertex);
    return 1;
}

int D_Print(PLGN::Polygon & polygon){
    int n = polygon.get_n();
    std::cout << "Maximum number of vertex: " << polygon.get_max_n() << "\n";
    std::cout << "Number of vertex: " << n << "\n";
    for(int i(0); i<n; ++i){
        std::cout << i << ":  x = " << polygon.get_coordinates(i+1).first << ";  y = " << polygon.get_coordinates(i+1).second << "\n";
    }
    return 1;
}