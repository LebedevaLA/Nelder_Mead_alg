#ifndef INCLUDE_FUN_H_
#define INCLUDE_FUN_H_
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

float function1_2d(vector<float>);
float function2_2d(vector<float>);
float function3_2d(vector<float>);
float function_Izom_2d( vector<float> point);
float function_Rezen_n( vector<float> point);
float function_Rastr_n(vector<float> point);
float function_Sphere_n(vector<float> point);

class Nelder_Mead{
    private:
        vector<vector<float>> symplex;
        int problem_size;
        int point_size;
        float alpha = 1.0; // Коэффициент отражения
        float beta = 0.5;//сжатие
        float gamma = 2.0;//растяжение
        int maxiter = 10;
        vector<float> best_point;
        vector<float> good_point;
        vector<float> worst_point;
        vector <float> middle_point;
        vector<float> reflection_point;
        vector<float> compression_point;
        vector<float> expansion_point;

        using FuncPtr = float(*)(vector<float>);
        FuncPtr function;
        
        map <vector<float>, float> Create_map();
        void Sort_Symplex();
        vector<float> Find_Middle_point_best_good();
        vector<float> Find_Center_point_worst_middle();
        vector<float> reflection();
        vector<float> compression();
        vector<float> expansion(vector<float> reflection_point);
        vector<float> Nelder_mead();

    public:
        vector<float> Get_Nelder_Mead_result();
        void init_base_symplex();
        Nelder_Mead(int problem_size, vector<vector<float>> initual_points, FuncPtr func);
        Nelder_Mead(int problem_size,FuncPtr func, vector<vector<float>> initual_points, float alpha, float beta, float gamma);
        Nelder_Mead(int problem_size, FuncPtr func, float alpha, float beta, float gamma);
        Nelder_Mead(int problem_size, FuncPtr func);
        Nelder_Mead(int problem_size, FuncPtr func, int count_iter);
        Nelder_Mead(int problem_size,vector<vector<float>> initual_points, FuncPtr func, int count_iter);
        void Print_symplex();
        void Print_coefficients();
        vector<vector<float>> Get_Symplex();
        vector<float> Get_Middle_Point();
        vector<float> Get_Reflection_Point();
        vector<float> Get_Compression_Point();
        vector<float> Get_Expansion_point_Point();

};



#endif 