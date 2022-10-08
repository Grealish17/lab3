#include "polygon.h"

namespace PLGN{

    int Polygon::get_max_n() const{
        return max_n;
    }

    int Polygon::get_n() const{
        return n;
    }

    void Polygon::set_coordinates(int data_n, Vertex * data_vertex){
        if(data_n >= 0){
            n = data_n;
        }
        else{
            throw std::invalid_argument("Incorrect data");
        }
        for(int i(0); i<n; ++i){
            vertex[i] = data_vertex[i];
        }
    }

    Polygon::Polygon(){
        n = 0;
    }

    Polygon::Polygon(float x, float y){
        n = 1;
        vertex[0].x = x;
        vertex[0].y = y;
    }

    Polygon::Polygon(int n, Vertex * vertex){
        if(n >= 1 && n <= max_n){
            this->n = n;
            for(int i(0); i<n; ++i){
                this->vertex[i] = vertex[i];
            }
        }
        else{
            throw std::invalid_argument("Incorrect data");
        }
    }

    Vertex Polygon::get_coordinates(int k) const{
        if(k <= n && k > 0){
            return vertex[k - 1];
        }
        else{
            throw std::invalid_argument("Incorrect data");
        }
    }

    void Polygon::add_vertex(float x, float y){
        if(n == max_n){
            throw std::invalid_argument("Array overflow");
        }
        else{
            vertex[n].x = x;
            vertex[n].y = y;
            ++n;
        }
    }

    Vertex Polygon::center_of_gravity() const{
        if(n == 0){
            throw std::invalid_argument("Polygon is empty");
        }
        else{
            Polygon polygon = *this;

            for(int i(n-2); i>=0; --i){
                polygon.vertex[i].x = (float)((polygon.vertex[i].x + polygon.vertex[i+1].x * (0.0 + n-2 - i+1))/(1 + n-2 - i+1));
                polygon.vertex[i].y = (float)((polygon.vertex[i].y + polygon.vertex[i+1].y * (0.0 + n-2 - i+1))/(1 + n-2 - i+1));
            }
            return polygon.vertex[0];
        }
    }

    void Polygon::rotate(float x0, float y0, int fi){
        if(fi % 90 == 0){
            for(int i(0); i<n; ++i){
                float x, y;
                x = (float)(x0 + (vertex[i].x - x0)*cos(PI * fi/180) - (vertex[i].y - y0)*sin(PI * fi/180));
                y = (float)(y0 + (vertex[i].x - x0)*sin(PI * fi/180) + (vertex[i].y - y0)*cos(PI * fi/180));
                vertex[i].x = x;
                vertex[i].y = y;
            }
        }
        else{
            throw std::invalid_argument("Array overflow");
        }
    }

    void Polygon::parallel_transfer(float x, float y){
        for(int i(0); i<n; ++i){
            vertex[i].x += x;
            vertex[i].y += y;
        }
    }

    void Polygon::print(std::ostream& os) const{
        os << "Maximum number of vertex: " << max_n << "\n";
        os << "Number of vertex: " << n << "\n";
        for(int i(0); i<n; ++i){
            os << i+1 << ":  x = " << vertex[i].x << ";  y = " << vertex[i].y << "\n";
        }
    }
}