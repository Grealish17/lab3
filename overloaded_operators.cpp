#include "polygon.h"

namespace PLGN{
    Vertex Polygon::operator[](int i) const{
        return this->get_coordinates(i);
    }

    Polygon operator+(const Polygon& p1, const Polygon& p2){
        Vertex new_vertex[p1.n + p2.n];
        for(int i(0); i<p1.n; ++i){
            new_vertex[i] = p1.vertex[i];
        }
        for(int i(0); i<p2.n; ++i){
            new_vertex[p1.n + i] = p2.vertex[i];
        }
        Polygon polygon = Polygon(p1.n + p2.n, new_vertex);
        return polygon;
    }

    Polygon& operator+=(Polygon& p1, const Polygon& p2){
        if(p1.n + p2.n > p1.max_n){
            throw std::invalid_argument("Array overflow");
        }
        else{
            for(int i(0); i<p2.n; ++i){
                p1.add_vertex(p2.vertex[i].x, p2.vertex[i].y);
            }
            return p1;
        }
    }

    Polygon& operator+=(Polygon& p1, const Vertex& v){
        p1.add_vertex(v.x, v.y);
        return p1;
    }

    Vertex Polygon::operator*() const{
        return this->center_of_gravity();
    }

    std::ostream& operator<<(std::ostream& strm, const Polygon& polygon){
        polygon.print(strm);
        return strm;
    }
}