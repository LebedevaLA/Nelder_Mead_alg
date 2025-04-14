#include <gtest/gtest.h>
#include "fun.h"

TEST(TestSymplex, test1) {
    Point p1 = Point({4.0, 4.0});
    Point p2 = Point({2.0, 4.0});
    Point p3 = Point({2.0, 3.0});
    vector<Point> points = {p1, p2, p3};
    int point_size = 2;
    int problem_size = 3;
    int count_iter = 1;
    Point s1 = Point({2.0, 3.0});
    Point s2 = Point({2.0, 4.0});
    Point s3 = Point({1.5, 3.375});
    vector<Point> sorted_points = {s1, s2, s3};
    
    Nelder_Mead algorithm = Nelder_Mead(problem_size, points,function2_2d,count_iter);
    algorithm.Get_Nelder_Mead_result();
    vector<Point> result = algorithm.Get_Symplex();
    EXPECT_EQ(sorted_points, result);
}


TEST(TestMiddlePoint, test1) {
    Point p1 = Point({4.0, 4.0});
    Point p2 = Point({2.0, 4.0});
    Point p3 = Point({2.0, 3.0});
    vector<Point> points = {p1, p2, p3};
    int point_size = 2;
    int problem_size = 3;
    int count_iter = 1;
    vector<double> middle {2.0, 3.5};

    Nelder_Mead algorithm = Nelder_Mead(problem_size, points,function2_2d,count_iter);
    algorithm.Get_Nelder_Mead_result();
    Point result = algorithm.Get_Middle_Point();
    EXPECT_EQ(middle, result.GetPoint());
}

TEST(TestReflectionPoint, test1) {
    Point p1 = Point({4.0, 4.0});
    Point p2 = Point({2.0, 4.0});
    Point p3 = Point({2.0, 3.0});
    vector<Point> points = {p1, p2, p3};
    int point_size = 2;
    int problem_size = 3;
    int count_iter = 1;
    vector<double> reflec_point = {0.0, 3.0};
    Nelder_Mead algorithm = Nelder_Mead(problem_size, points,function2_2d,count_iter);
    algorithm.Get_Nelder_Mead_result();
    Point result = algorithm.Get_Reflection_Point();
    EXPECT_EQ(reflec_point, result.GetPoint());
}

TEST(TestCompressionPoint, test1) {
    Point p1 = Point({4.0, 4.0});
    Point p2 = Point({2.0, 4.0});
    Point p3 = Point({2.0, 3.0});
    vector<Point> points = {p1, p2, p3};
    int point_size = 2;
    int problem_size = 3;
    int count_iter = 1;
    vector<double> compr_point = {1.5,3.375};
    Nelder_Mead algorithm = Nelder_Mead(problem_size, points,function2_2d,count_iter);
    algorithm.Get_Nelder_Mead_result();
    Point result = algorithm.Get_Compression_Point();
    EXPECT_EQ(compr_point, result.GetPoint());
}

TEST(TestExpansionPoint, test1) {
    int point_size = 2;
    int problem_size = 3;
    int count_iter = 7;
    vector<double> exp_point = {0.5, 1.5};
    Nelder_Mead algorithm = Nelder_Mead(problem_size, function2_2d,count_iter);
    algorithm.Get_Nelder_Mead_result();
    Point result = algorithm.Get_Expansion_point_Point();
    EXPECT_EQ(exp_point, result.GetPoint());
}

TEST(Test_Nelder_Mead, test1) {
    int point_size = 2;
    int problem_size = 3;
    vector<double> res_point = {2.0, 3.0};
    Nelder_Mead algorithm = Nelder_Mead(problem_size, function2_2d);
    Point result = algorithm.Get_Nelder_Mead_result();
    EXPECT_EQ(res_point, result.GetPoint());
}

TEST(Test_Nelder_Mead, test2) {
    int point_size = 2;
    int problem_size = 3;
    vector<double> res_point = {1.0, 4.0};
    Nelder_Mead algorithm = Nelder_Mead(problem_size, function1_2d);
    Point result = algorithm.Get_Nelder_Mead_result();
    EXPECT_EQ(res_point, result.GetPoint());
}

TEST(Test_Nelder_Mead, test3) {
    Point p1 = Point({0.0, 1.0});
    Point p2 = Point({1.0, 1.0});
    Point p3 = Point({2.0, 1.0});
    vector<Point> points = {p1, p2, p3};
    int point_size = 2;
    int problem_size = 3;
    vector<double> res_point = {1.0, 1.0};
    Nelder_Mead algorithm = Nelder_Mead(problem_size, points,function3_2d);
    Point result = algorithm.Get_Nelder_Mead_result();
    EXPECT_EQ(res_point, result.GetPoint());
}

TEST(Test_Nelder_Mead, test4_Rezen_n) {
    Point p1 = Point({1.0, 1.0, 1.0, 1.0});
    Point p2 = Point({1.5, 1.0, 1.0, 1.0});
    Point p3 = Point({1.0, 1.5, 1.0, 1.0});
    Point p4 = Point({1.0, 1.0, 1.5, 1.0});
    Point p5 = Point({1.0, 1.0, 1.0, 1.5});
    vector<Point> points = {p1, p2,p3, p4, p5};
    int point_size = 4;
    int problem_size = 5;
    vector<double> res_point = {1.0, 1.0, 1.0, 1.0};
    Nelder_Mead algorithm = Nelder_Mead(problem_size, points,  function_Rezen_n);
    Point result = algorithm.Get_Nelder_Mead_result();
    EXPECT_EQ(res_point, result.GetPoint());
}

TEST(Test_Nelder_Mead, test5_Izom) {
    int point_size = 2;
    int problem_size = 3;
    vector<double> res_point = {3.14, 3.14};
    Nelder_Mead algorithm = Nelder_Mead(problem_size, function_Izom_2d);
    vector<double> result = (algorithm.Get_Nelder_Mead_result()).GetPoint();
    vector<double> round_res = {round(result[0] * 100) / 100, round(result[1] * 100) / 100};
    EXPECT_EQ(res_point, round_res);
}

TEST(Test_Nelder_Mead, test6_Rastr_n) {
    int point_size = 6;
    int problem_size = 7;
    vector<double> res_point = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    Nelder_Mead algorithm = Nelder_Mead(problem_size, function_Rastr_n);
    Point result = algorithm.Get_Nelder_Mead_result();
    EXPECT_EQ(res_point, result.GetPoint());
}

TEST(Test_Nelder_Mead, test7_Sphere_n) {
    int point_size = 6;
    int problem_size = 7;
    vector<double> res_point = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    Nelder_Mead algorithm = Nelder_Mead(problem_size, function_Sphere_n);
    Point result = algorithm.Get_Nelder_Mead_result();
    EXPECT_EQ(res_point, result.GetPoint());
}
