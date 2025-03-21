#include <gtest/gtest.h>
#include "fun.h"

TEST(TestSymplex, test1) {
    vector<vector<float>> points = {{4.0, 4.0},{2.0, 4.0}, {2.0, 3.0}};
    int point_size = 2;
    int problem_size = 3;
    int count_iter = 1;
    vector<vector<float>> sorted_points = {{2.0, 3.0},{2.0, 4.0},{1.5, 3.375}};

    Nelder_Mead algorithm = Nelder_Mead(problem_size, points,function2_2d,count_iter);
    algorithm.Get_Nelder_Mead_result();
    vector<vector<float>> result = algorithm.Get_Symplex();
    EXPECT_EQ(sorted_points, result);
}


TEST(TestMiddlePoint, test1) {
    vector<vector<float>> points = {{4.0, 4.0},{2.0, 4.0}, {2.0, 3.0}};
    int point_size = 2;
    int problem_size = 3;
    int count_iter = 1;
    vector<float> middle {2.0, 3.5};

    Nelder_Mead algorithm = Nelder_Mead(problem_size, points,function2_2d,count_iter);
    algorithm.Get_Nelder_Mead_result();
    vector<float> result = algorithm.Get_Middle_Point();
    EXPECT_EQ(middle, result);
}

TEST(TestReflectionPoint, test1) {
    vector<vector<float>> points = {{4.0, 4.0},{2.0, 4.0}, {2.0, 3.0}};
    int point_size = 2;
    int problem_size = 3;
    int count_iter = 1;
    vector<float> reflec_point = {0.0,3.0};
    Nelder_Mead algorithm = Nelder_Mead(problem_size, points,function2_2d,count_iter);
    algorithm.Get_Nelder_Mead_result();
    vector<float> result = algorithm.Get_Reflection_Point();
    EXPECT_EQ(reflec_point, result);
}

TEST(TestCompressionPoint, test1) {
    vector<vector<float>> points = {{4.0, 4.0},{2.0, 4.0}, {2.0, 3.0}};
    int point_size = 2;
    int problem_size = 3;
    int count_iter = 1;
    vector<float> compr_point = {1.5,3.375};
    Nelder_Mead algorithm = Nelder_Mead(problem_size, points,function2_2d,count_iter);
    algorithm.Get_Nelder_Mead_result();
    vector<float> result = algorithm.Get_Compression_Point();
    EXPECT_EQ(compr_point, result);
}

TEST(TestExpansionPoint, test1) {
    int point_size = 2;
    int problem_size = 3;
    int count_iter = 7;
    vector<float> exp_point = {0.5, 1.5};
    Nelder_Mead algorithm = Nelder_Mead(problem_size, function2_2d,count_iter);
    algorithm.Get_Nelder_Mead_result();
    vector<float> result = algorithm.Get_Expansion_point_Point();
    EXPECT_EQ(exp_point, result);
}

TEST(Test_Nelder_Mead, test1) {
    int point_size = 2;
    int problem_size = 3;
    vector<float> res_point = {2.0, 3.0};
    Nelder_Mead algorithm = Nelder_Mead(problem_size, function2_2d);
    vector<float> result = algorithm.Get_Nelder_Mead_result();
    EXPECT_EQ(res_point, result);
}

TEST(Test_Nelder_Mead, test2) {
    int point_size = 2;
    int problem_size = 3;
    vector<float> res_point = {1.0, 4.0};
    Nelder_Mead algorithm = Nelder_Mead(problem_size, function1_2d);
    vector<float> result = algorithm.Get_Nelder_Mead_result();
    EXPECT_EQ(res_point, result);
}

TEST(Test_Nelder_Mead, test3) {
    vector<vector<float>> points = {{0.0, 1.0},{1.0, 1.0}, {2.0, 1.0}};
    int point_size = 2;
    int problem_size = 3;
    vector<float> res_point = {1.0, 1.0};
    Nelder_Mead algorithm = Nelder_Mead(problem_size, points,function3_2d);
    vector<float> result = algorithm.Get_Nelder_Mead_result();
    EXPECT_EQ(res_point, result);
}
