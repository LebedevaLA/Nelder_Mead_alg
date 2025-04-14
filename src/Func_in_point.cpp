#include "fun.h"

FuncinPoint::FuncinPoint(Point point,  FuncPtr func){
    vector<double> p = point.GetPoint();
    f_in_point = func(p);
}
bool FuncinPoint::operator<(const FuncinPoint& other) const {
    return f_in_point < other.f_in_point;
}