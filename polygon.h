#include <iostream>
#include <cmath>
#define PI 3.14159265

#define N_MAX 5

namespace PLGN{

    struct Vertex{
        float x;
        float y;
    };

    class Polygon{
    private:
        const int max_n = N_MAX;
        int n;
        Vertex vertex[N_MAX] = {};
    public:
        int get_max_n() const;

        int get_n() const;

        void set_coordinates(int data_n, Vertex * data_vertex);

        Polygon();

        Polygon(float x, float y);

        Polygon(int n, Vertex * vertex);

        Vertex get_coordinates(int k);

        void add_vertex(float x, float y);

        Vertex center_of_gravity();

        void rotate(float x0, float y0, int fi);

        void parallel_transfer(float x, float y);
    };
}


