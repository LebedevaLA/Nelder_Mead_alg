#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

double function1_2d(vector<double>);
double function2_2d(vector<double>);
double function3_2d(vector<double>);
double function_Izom_2d( vector<double> point);
double function_Rezen_n( vector<double> point);
double function_Rastr_n(vector<double> point);
double function_Sphere_n(vector<double> point);

class Point{
    public:
        vector<double> point;
        Point(int n);
        Point(vector<double> point);
        Point();
        vector<double> GetPoint();
        void Print_point();
        void ChangeiPoint(int i, double num);
        double GetiPoint(int i);
        bool  operator==(const Point& other) const;
};

class FuncinPoint{
    private:
        double f_in_point;
        using FuncPtr = double(*)(vector< double>);
        FuncPtr function;
    public:
        FuncinPoint(Point point,  FuncPtr func);
        bool operator<(const FuncinPoint& other) const;
    
};

class Nelder_Mead{
    private:
        vector<Point> symplex;
        int problem_size;
        int point_size;
        float alpha = 1.0; // Коэффициент отражения
        float beta = 0.5;//сжатие
        float gamma = 2.0;//растяжение
        int maxiter = 1000;
        Point best_point;
        Point good_point;
        Point worst_point;
        Point middle_point;
        Point reflection_point;
        Point compression_point;
        Point expansion_point;

        using FuncPtr = double(*)(vector<double>);
        FuncPtr function;

        map <Point, double> Create_map();
        void Sort_Symplex();
        Point Find_Middle_point_best_good();
        Point Find_Center_point_worst_middle();
        Point reflection();
        Point compression();
        Point expansion(Point reflection_point);
        Point Nelder_mead();
       
    public:
        bool comparePoints(const Point& a, const Point& b);
        Point Get_Nelder_Mead_result();
        void init_base_symplex();
        Nelder_Mead(int problem_size, vector<Point> initual_points, FuncPtr func);
        Nelder_Mead(int problem_size,FuncPtr func, vector<Point> initual_points, float alpha, float beta, float gamma);
        Nelder_Mead(int problem_size, FuncPtr func, float alpha, float beta, float gamma);
        Nelder_Mead(int problem_size, FuncPtr func);
        Nelder_Mead(int problem_size, FuncPtr func, int count_iter);
        Nelder_Mead(int problem_size,vector<Point> initual_points, FuncPtr func, int count_iter);
        void Print_symplex();
        void Print_coefficients();
        vector<Point> Get_Symplex();
        Point Get_Middle_Point();
        Point Get_Reflection_Point();
        Point Get_Compression_Point();
        Point Get_Expansion_point_Point();
    
};

