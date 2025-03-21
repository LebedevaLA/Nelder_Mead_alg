
#include "fun.h"

float function1_2d( vector<float> point){
    float x = point[0];
    float y = point[1];
    return x * x + y * y + x*y - 6*x - 9*y;
}

float function2_2d( vector<float> point){
    float x = point[0];
    float y = point[1];
    return (x -2) * (x - 2) + (y - 3) * (y - 3);
}

float function3_2d( vector<float> point){
    float x = point[0];
    float y = point[1];
    return  (1 - x)*(1 - x) + 100 * (y - x * x)*(y - x * x);
}
