
#include "fun.h"

map <vector<float>, float> Nelder_Mead::Create_map(){
    map <vector<float>, float> dict_point_func;
    for (int index = 0; index < problem_size; index ++){
        dict_point_func[symplex[index]] = function(symplex[index]);
    }
    return(dict_point_func);
}

void Nelder_Mead::Sort_Symplex(){
    map <vector<float>, float> dict_point_func = Create_map();
    for (int index =0; index < problem_size - 1; index++){
        for(int iter = index +1; iter < problem_size; iter++){
            if (dict_point_func[symplex[index]] > dict_point_func[symplex[iter]]){
                vector<float> tmp = symplex[index];
                symplex[index] = symplex[iter];
                symplex[iter] = tmp;
            }
        }
    }
    best_point = symplex[0];
    good_point = symplex[ceil(problem_size/2)];
    worst_point = symplex[problem_size - 1];
}

vector<float> Nelder_Mead::Find_Middle_point_best_good(){
    vector<float> middle_point;
    for (int index = 0; index < point_size; index++){
        middle_point.push_back(0.0);
    }
    for (int index = 0; index < problem_size - 1; index++){
        for (int iter = 0; iter < point_size; iter++){
            middle_point[iter] += symplex[index][iter];
        }
    }
    for (int index =0; index< point_size; index++){
        middle_point[index] /= point_size;
    }
    return(middle_point);
}

vector<float> Nelder_Mead::Find_Center_point_worst_middle(){
    vector<float> center_point;
    for (int index = 0; index < point_size; index++){
        center_point.push_back(0.0);
    }
    for (int iter = 0; iter < point_size; iter++){
        center_point[iter] += (worst_point[iter] + middle_point[iter]);
    }
    for (int index =0; index< point_size; index++){
        center_point[index] /= point_size;
    }
    return(center_point);
}

vector<float> Nelder_Mead::reflection(){
    vector<float> reflection_point;
    for (int index = 0; index < point_size; index++){
        reflection_point.push_back(0.0);
    }
    for (int index = 0; index < point_size; index++){
        reflection_point[index] = middle_point[index] + alpha*(middle_point[index] - worst_point[index]);
    }
    return (reflection_point);
}

vector<float> Nelder_Mead::compression(){
    vector<float> compression_point;
    for (int index = 0; index < point_size; index++){
        compression_point.push_back(0.0);
    }
    for (int index = 0; index < point_size; index++){
        compression_point[index] = middle_point[index] + beta*(worst_point[index] - middle_point[index]);
    }
    return (compression_point);
}

vector<float> Nelder_Mead::expansion(vector<float> reflection_point){
    vector<float> expansion_point;
    for (int index = 0; index < point_size; index++){
        expansion_point.push_back(0.0);
    }
    for (int index = 0; index < point_size; index++){
        expansion_point[index] = middle_point[index] + gamma*(middle_point[index] - reflection_point[index]);
    }
    return (expansion_point);
}

vector<float> Nelder_Mead::Nelder_mead(){
    for (int iter = 0; iter<maxiter; iter++){
        Sort_Symplex();
        middle_point = Find_Middle_point_best_good();
        reflection_point = reflection();
        if (function(reflection_point) < function(good_point)){
            worst_point = reflection_point;
        }else{
            if (function(reflection_point) < function(worst_point)){
                worst_point = reflection_point;
            }
            vector<float> center_point = Find_Center_point_worst_middle();
            if (function(center_point) < function(worst_point)){
                worst_point = center_point;
            }
        }
        if (function(reflection_point)< function(best_point)){
            expansion_point = expansion(reflection_point);
            if (function(expansion_point) < function(reflection_point)){
                worst_point = expansion_point;
            }else{
                worst_point = reflection_point;
            }
        }
        if (function(reflection_point)> function(good_point)){
            compression_point = compression();
            if (function(compression_point) < function(worst_point)){
                worst_point = compression_point;
            }
        }
        symplex[0] = best_point;
        symplex[ceil(problem_size/2)] = good_point;
        symplex[problem_size - 1] = worst_point;
    }
    return(best_point);
}

vector<float> Nelder_Mead::Get_Nelder_Mead_result(){
    return (Nelder_mead());
}
vector<float> Nelder_Mead::Get_Middle_Point(){
    return (middle_point);
}
vector<float> Nelder_Mead::Get_Reflection_Point(){
    return (reflection_point);
}
vector<float> Nelder_Mead::Get_Compression_Point(){
    return (compression_point);
}
vector<float> Nelder_Mead::Get_Expansion_point_Point(){
    return (expansion_point);
}
vector<vector<float>> Nelder_Mead::Get_Symplex(){
    return symplex;
}
void Nelder_Mead::init_base_symplex(){
    vector<float> initialPoint;
    for (int index = 0; index < problem_size; index++){
        initialPoint.push_back(0.0);
    }
    symplex.push_back(initialPoint);
    float delta = 1.0;
    for (int index = 1; index < problem_size; index++) {
        symplex.push_back(initialPoint);
        symplex[index][index-1] += delta;
    }
}

Nelder_Mead::Nelder_Mead(int problem_size, vector<vector<float>> initual_points, FuncPtr func){
    function = func;
    symplex = initual_points;
    this -> problem_size = problem_size;
    point_size = problem_size - 1;
}
Nelder_Mead::Nelder_Mead(int problem_size, FuncPtr func, vector<vector<float>> initual_points, float alpha, float beta, float gamma){
    function = func;
    symplex = initual_points;
    this -> problem_size = problem_size;
    this -> alpha = alpha;
    this -> beta = beta;
    this -> gamma = gamma;
    point_size = problem_size - 1;
}
Nelder_Mead::Nelder_Mead(int problem_size,FuncPtr func, float alpha, float beta, float gamma){
    function = func;
    this -> problem_size = problem_size;
    this -> alpha = alpha;
    this -> beta = beta;
    this -> gamma = gamma;
    point_size = problem_size - 1;
    init_base_symplex();

}
Nelder_Mead::Nelder_Mead(int problem_size, FuncPtr func){
    function = func;
    this -> problem_size = problem_size;
    point_size = problem_size - 1;
    init_base_symplex();
}
Nelder_Mead::Nelder_Mead(int problem_size, FuncPtr func, int count_iter){
    function = func;
    maxiter = count_iter;
    this -> problem_size = problem_size;
    point_size = problem_size - 1;
    init_base_symplex();
}
Nelder_Mead::Nelder_Mead(int problem_size,vector<vector<float>> initual_points, FuncPtr func, int count_iter){
    function = func;
    maxiter = count_iter;
    this -> problem_size = problem_size;
    point_size = problem_size - 1;
    symplex = initual_points;
}
void Nelder_Mead::Print_symplex(){
    for (int index = 0; index < problem_size; index++){
        for (int iter = 0; iter < symplex[index].size(); iter++){
            cout << symplex[index][iter] << " ";
        }
        cout << endl;
    }
}
void Nelder_Mead::Print_coefficients(){
    cout << "Alfa"<< alpha << endl;
    cout << "Beta"<< beta << endl;
    cout << "Gamma"<< gamma << endl;
}

