#include <iostream>
#include <cmath>
#define PI 3.14159265

#define N_MAX 5

namespace PLGN{

    struct Vertex{
        int weight;
        float x;
        float y;
    };

    class Polygon{
    private:
        const int max_n = N_MAX;
        int n;
        Vertex vertex[N_MAX] = {};
    public:
        int get_max_n() const{
            return max_n;
        }
        int get_n() const{
            return n;
        }
        void set_n(int data_n){
            if(data_n >= 0){
                n = data_n;
            }
            else{
                throw std::invalid_argument("Incorrect data");
            }
        }
        void set_coordinates(Vertex * data_vertex){
            for(int i(0); i<n; ++i){
                vertex[i] = data_vertex[i];
            }
        }
        Polygon(){
            n = 0;
        }
        Polygon(float x, float y){
            n = 1;
            vertex[0].x = x;
            vertex[0].y = y;
        }
        Polygon(int n, Vertex * vertex){
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
        std::pair<float, float> get_coordinates(int k){
            if(k <= n && k > 0){
                return {vertex[k - 1].x, vertex[k - 1].y};
            }
            else{
                throw std::invalid_argument("Incorrect data");
            }
        }
        void add_vertex(float x, float y){
            if(n == max_n){
                throw std::invalid_argument("Array overflow");
            }
            else{
                vertex[n].x = x;
                vertex[n].y = y;
                ++n;
            }
        }
        std::pair<float, float> center_of_gravity(){
            if(n == 0){
                throw std::invalid_argument("Polygon is empty");
            }
            else{
                Polygon polygon = *this;

                for(int i(0); i<n; ++i){
                    polygon.vertex[i].weight = 1;
                }

                for(int i(n-2); i>=0; --i){
                    polygon.vertex[i].x = (polygon.vertex[i].x * (float)polygon.vertex[i].weight + polygon.vertex[i+1].x * (float)polygon.vertex[i+1].weight)/(float)(polygon.vertex[i].weight + polygon.vertex[i+1].weight);
                    polygon.vertex[i].y = (polygon.vertex[i].y * (float)polygon.vertex[i].weight + polygon.vertex[i+1].y * (float)polygon.vertex[i+1].weight)/(float)(polygon.vertex[i].weight + polygon.vertex[i+1].weight);
                    polygon.vertex[i].weight = polygon.vertex[i].weight + polygon.vertex[i+1].weight;
                }
                return {polygon.vertex[0].x, polygon.vertex[0].y};
            }
        }
        void rotate(float x0, float y0, int fi){
            if(fi % 90 == 0){
                for(int i(0); i<n; ++i){
                    float x, y;
                    x = x0 + (vertex[i].x - x0)*cos(PI * (float)fi/180) - (vertex[i].y - y0)*sin(PI * (float)fi/180);
                    y = y0 + (vertex[i].x - x0)*sin(PI * (float)fi/180) + (vertex[i].y - y0)*cos(PI * (float)fi/180);
                    vertex[i].x = x;
                    vertex[i].y = y;
                }
            }
            else{
                throw std::invalid_argument("Array overflow");
            }
        }
        void parallel_transfer(float x, float y){
            for(int i(0); i<n; ++i){
                vertex[i].x += x;
                vertex[i].y += y;
            }
        }
    };
}


int dialog(const char *msgs[], int);
int D_Set_Data(PLGN::Polygon &);
int D_Print(PLGN::Polygon &);
int D_Center_Of_Gravity(PLGN::Polygon &);
int D_Add_Vertex(PLGN::Polygon &);
int D_Rotate_On_Angle(PLGN::Polygon &);
int D_Parallel_Transfer(PLGN::Polygon &);
int D_Get_Coordinates(PLGN::Polygon &);