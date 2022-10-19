#include <iostream>
#include <cmath>
#include <cstring>
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

        Polygon(Vertex v);

        Polygon(int n, Vertex * vertex);

        void add_vertex(float x, float y);

        Vertex center_of_gravity() const;

        void rotate(float x0, float y0, int fi);

        void parallel_transfer(float x, float y);

        void print(std::ostream& os) const;

        //OVERLOADED OPERATORS

        const Vertex& operator[](int i) const;

        Vertex& operator[](int i);

        friend Polygon operator+(const Polygon& p1, const Polygon& p2);

        friend Polygon& operator+=(Polygon& p1, const Polygon& p2);

        Vertex operator*() const;

        friend std::ostream& operator<<(std::ostream& strm, const Polygon& polygon);
    };
}