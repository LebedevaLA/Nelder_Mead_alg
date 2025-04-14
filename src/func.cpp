
#include "fun.h"

double function1_2d( vector<double> point){
    double x = point[0];
    double y = point[1];
    return x * x + y * y + x*y - 6*x - 9*y;
}

double function2_2d( vector<double> point){
    double x = point[0];
    double y = point[1];
    return (x -2) * (x - 2) + (y - 3) * (y - 3);
}

double function3_2d( vector<double> point){
    double x = point[0];
    double y = point[1];
    return  (1 - x)*(1 - x) + 100 * (y - x * x)*(y - x * x);
}
double function_Izom_2d( vector<double> point){
    double x = point[0];
    double y = point[1];
    return -cos(x) * cos(y) * M_E *(-((x - M_PI) * (x - M_PI) + (y - M_PI) * (y - M_PI)));
}
double function_Rezen_n( vector<double> point){
    double res = 0;
    for (int i = 0; i < point.size() - 1; i++){
        res += (1 - point[i]) * (1 - point[i]) + 100 * (point[i+1] - point[i]*point[i]) * (point[i+1] - point[i]*point[i]);
    }
    return res;
}

double function_Rastr_n(vector<double> point){
    double res = 0;
    for (int i = 0; i < point.size() - 1; i++){
        res += point[i] * point[i] - 10*cos(double(2 * M_PI * point[i]));
    }
    return (10*point.size() + res);
}
double function_Sphere_n(vector<double> point){
    double res = 0;
    for (int i = 0; i < point.size(); i++){
        res += point[i] * point[i];
    }
    return res;
}


