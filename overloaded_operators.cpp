#include "polygon.h"

namespace PLGN{
    const Vertex& Polygon::operator[](int i) const{
        if(i < n && i >= 0){
            return vertex[i];
        }
        else{
            throw std::invalid_argument("Incorrect data");
        }
    }

    Vertex& Polygon::operator[](int i){
        if(i < n && i >= 0){
            return vertex[i];
        }
        else{
            throw std::invalid_argument("Incorrect data");
        }
    }

    Polygon operator+(const Polygon& p1, const Polygon& p2){
        Vertex new_vertex[p1.n + p2.n];
        memcpy(new_vertex, p1.vertex, p1.n*sizeof(Vertex));
        memcpy(new_vertex + p1.n, p2.vertex, p2.n*sizeof(Vertex));
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

    Vertex Polygon::operator*() const{
        return this->center_of_gravity();
    }

    std::ostream& operator<<(std::ostream& strm, const Polygon& polygon){
        polygon.print(strm);
        return strm;
    }
}