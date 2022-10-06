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
        std::cout << "OK\n";
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
        std::cout << i+1 << ":  x = " << polygon.get_coordinates(i+1).first << ";  y = " << polygon.get_coordinates(i+1).second << "\n";
    }
    return 1;
}

int D_Center_Of_Gravity(PLGN::Polygon & polygon){
    try{
        float x = polygon.center_of_gravity().first;
        float y = polygon.center_of_gravity().second;
        std::cout << "Center of gravity:  x = " << x << " ,  y = " << y << "\n";
    }
    catch(std::invalid_argument& exception){
        std::cout << "Polygon is empty\n";
    }
    return 1;
}

int D_Add_Vertex(PLGN::Polygon & polygon){
    float x, y;
    std::cout << "Enter first coordinate, x = : ";
    std::cin >> x;
    std::cout << "Enter second coordinate, y = : ";
    std::cin >> y;
    try{
        polygon.add_vertex(x, y);
        std::cout << "OK\n";
    }
    catch(std::invalid_argument& exception){
        std::cout << "Polygon has max number of vertex: " << polygon.get_max_n() << "\n";
    }
    return 1;
}

int D_Rotate_On_Angle(PLGN::Polygon & polygon){
    float x0, y0;
    int fi;
    std::cout << "Enter first coordinate of the point, x = : ";
    std::cin >> x0;
    std::cout << "Enter second coordinate of the point, y = : ";
    std::cin >> y0;
    std::cout << "Enter angle in degrees multiple of 90, fi = : ";
    std::cin >> fi;
    try{
        polygon.rotate(x0, y0, fi);
        std::cout << "OK\n";
    }
    catch(std::invalid_argument& exception){
        std::cout << "Angle must be multiple of 90!\n";
    }
    return 1;
}

int D_Parallel_Transfer(PLGN::Polygon & polygon){
    float x, y;
    std::cout << "Enter first coordinate, x = : ";
    std::cin >> x;
    std::cout << "Enter second coordinate, y = : ";
    std::cin >> y;

    polygon.parallel_transfer(x, y);
    std::cout << "OK\n";
    return 1;
}

int D_Get_Coordinates(PLGN::Polygon & polygon){
    int k;
    std::cout << "Enter number of vertex: ";
    std::cin >> k;
    try{
        float x = polygon.get_coordinates(k).first;
        float y = polygon.get_coordinates(k).second;
        std::cout << "Coordinates of this vertex:  x = " << x << " ,  y = " << y << "\n";
    }
    catch(std::invalid_argument& exception){
        std::cout << "Polygon has only " << polygon.get_n() << " vertex\n";
    }
    return 1;
}