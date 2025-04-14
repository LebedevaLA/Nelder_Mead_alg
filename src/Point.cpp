#include "fun.h"

Point::Point(int n){
    for (int index = 0; index < n; index++){
        point.push_back(0);
    }
}
Point::Point() {};
Point::Point(vector<double> point){
    for (int index = 0; index < point.size(); index++){
        this->point.push_back(point[index]);
    }
}
vector<double> Point::GetPoint(){
    return (point);
}
void Point::ChangeiPoint(int i, double num){
    point[i] = num;
}
double Point::GetiPoint(int i){
    return(point[i]);
}
void Point::Print_point(){
    for (int index = 0; index < point.size(); index++){
        cout << point[index]<< " ";
    }
    cout<<endl;
}
bool  Point::operator==(const Point& other) const {
    return point == other.point;
}