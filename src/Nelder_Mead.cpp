#include "fun.h"

bool Nelder_Mead::comparePoints(const Point& a, const Point& b) {
    FuncinPoint fa(a, function);
    FuncinPoint fb(b, function);
    return fa < fb;
}
void Nelder_Mead::Sort_Symplex(){
    sort(symplex.begin(), symplex.end(), [this](const Point& a, const Point& b) {
        return comparePoints(a, b);
    });
    best_point = symplex[0];
    good_point = symplex[ceil(problem_size / 2)];
    worst_point = symplex[problem_size - 1];
}

Point Nelder_Mead::Find_Middle_point_best_good(){
    Point middle_point = Point(point_size);
    for (int index = 0; index < problem_size - 1; index++) {
        for (int iter = 0; iter < point_size; iter++) {
            middle_point.ChangeiPoint(iter, middle_point.GetiPoint(iter) + symplex[index].GetiPoint(iter));
        }
    }
    for (int index = 0; index < point_size; index++) {
        middle_point.ChangeiPoint(index, middle_point.GetiPoint(index) / (problem_size - 1));
    }
    return (middle_point);
}

Point Nelder_Mead::Find_Center_point_worst_middle(){
    Point center_point = Point(point_size);
    for (int iter = 0; iter < point_size; iter++){
        center_point.ChangeiPoint(iter, center_point.GetiPoint(iter) + worst_point.GetiPoint(iter) + middle_point.GetiPoint(iter));
    }
    for (int index =0; index< point_size; index++){
        center_point.ChangeiPoint(index, center_point.GetiPoint(index)/point_size);
    }
    return(center_point);
}

Point Nelder_Mead::reflection(){
    Point reflection_point = Point(point_size);
    for (int index = 0; index < point_size; index++){
        reflection_point.ChangeiPoint(index, middle_point.GetiPoint(index) + 
        alpha*(middle_point.GetiPoint(index) - worst_point.GetiPoint(index)));
    }
    return (reflection_point);
}

Point Nelder_Mead::compression(){
    Point compression_point = Point(point_size);
    for (int index = 0; index < point_size; index++){
        compression_point.ChangeiPoint(index, middle_point.GetiPoint(index) + 
        beta*(worst_point.GetiPoint(index) - middle_point.GetiPoint(index)));
    }
    return (compression_point);
}

Point Nelder_Mead::expansion(Point reflection_point){
    Point expansion_point = Point(point_size);
    for (int index = 0; index < point_size; index++){
        expansion_point.ChangeiPoint(index, middle_point.GetiPoint(index) + gamma*(middle_point.GetiPoint(index) - reflection_point.GetiPoint(index)));
    }
    return (expansion_point);
}

Point Nelder_Mead::Nelder_mead(){
    for (int iter = 0; iter<maxiter; iter++){
        Sort_Symplex();
        middle_point = Find_Middle_point_best_good();
        reflection_point = reflection();
        if (function(reflection_point.GetPoint()) < function(good_point.GetPoint())){
            worst_point = reflection_point;
        }else{
            worst_point = function(reflection_point.GetPoint()) < function(worst_point.GetPoint()) ? reflection_point : worst_point;
            Point center_point = Find_Center_point_worst_middle();
            worst_point = function(center_point.GetPoint()) < function(worst_point.GetPoint()) ? center_point : worst_point;
        }
        if (function(reflection_point.GetPoint())< function(best_point.GetPoint())){
            expansion_point = expansion(reflection_point);
            worst_point = function(expansion_point.GetPoint()) < function(reflection_point.GetPoint()) ? expansion_point : reflection_point;
        }
        if (function(reflection_point.GetPoint())> function(good_point.GetPoint())){
            compression_point = compression();
            worst_point = function(compression_point.GetPoint()) < function(worst_point.GetPoint()) ? compression_point : worst_point;
        }
        symplex[0] = best_point;
        symplex[ceil(problem_size/2)] = good_point;
        symplex[problem_size - 1] = worst_point;
    }
    return(best_point);
}

Point  Nelder_Mead::Get_Nelder_Mead_result(){
    return (Nelder_mead());
}
Point  Nelder_Mead::Get_Middle_Point(){
    return (middle_point);
}
Point Nelder_Mead::Get_Reflection_Point(){
    return (reflection_point);
}
Point Nelder_Mead::Get_Compression_Point(){
    return (compression_point);
}
Point Nelder_Mead::Get_Expansion_point_Point(){
    return (expansion_point);
}
vector<Point> Nelder_Mead::Get_Symplex(){
    return symplex;
}
void Nelder_Mead::init_base_symplex(){
    Point initialPoint = Point(point_size);
    symplex.push_back(initialPoint);
    float delta = 1.0;
    for (int index = 1; index < problem_size; index++) {
        symplex.push_back(initialPoint);
        double coord = symplex[index].GetiPoint(index-1);
        symplex[index].ChangeiPoint(index - 1, coord + delta);
    }
}

Nelder_Mead::Nelder_Mead(int problem_size, std::vector<Point> initual_points, FuncPtr func)
    : function(func), symplex(initual_points), problem_size(problem_size), point_size(problem_size - 1) {}

Nelder_Mead::Nelder_Mead(int problem_size, FuncPtr func, std::vector<Point> initual_points, float alpha, float beta, float gamma)
    : function(func), symplex(initual_points), problem_size(problem_size), alpha(alpha), beta(beta), gamma(gamma), point_size(problem_size - 1) {}

Nelder_Mead::Nelder_Mead(int problem_size, FuncPtr func, float alpha, float beta, float gamma)
    : function(func), problem_size(problem_size), alpha(alpha), beta(beta), gamma(gamma), point_size(problem_size - 1) {
    init_base_symplex();
}

Nelder_Mead::Nelder_Mead(int problem_size, FuncPtr func)
    : function(func), problem_size(problem_size), point_size(problem_size - 1) {
    init_base_symplex();
}

Nelder_Mead::Nelder_Mead(int problem_size, FuncPtr func, int count_iter)
    : function(func), maxiter(count_iter), problem_size(problem_size), point_size(problem_size - 1) {
    init_base_symplex();
}

Nelder_Mead::Nelder_Mead(int problem_size, std::vector<Point> initual_points, FuncPtr func, int count_iter)
    : function(func), maxiter(count_iter), problem_size(problem_size), point_size(problem_size - 1), symplex(initual_points) {}

void Nelder_Mead::Print_symplex(){
    for (int index = 0; index < symplex.size(); index++){
        symplex[index].Print_point();
    }
}
void Nelder_Mead::Print_coefficients(){
    cout << "Alfa"<< alpha << endl;
    cout << "Beta"<< beta << endl;
    cout << "Gamma"<< gamma << endl;
}

