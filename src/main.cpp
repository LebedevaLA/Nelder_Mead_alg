#include "fun.h"
void Do_Nelder_Mead( Nelder_Mead algorithm){
    cout<<"Start Symplex"<<endl;
    algorithm.Print_symplex();
    cout<<"Coefficients"<<endl;
    algorithm.Print_coefficients();
    cout <<"Answer"<<endl;
    vector<float> res = algorithm.Get_Nelder_Mead_result();
    for (int index =0; index < res.size(); index++){
        cout << res[index]<<" ";
    }
}

int main(){
    cout << "Input point_size" << endl;
    int point_size;
    cin >> point_size;
    int problem_size = point_size + 1;
    cout << "Do you know symplex?(y/n)" << endl;
    char answer;
    cin >> answer;
    vector < vector<float> > initial_points;
    bool have_initialsymplex = 0;
    if (answer == 'y' || answer == 'Y'){
        cout<<"Input coordinates"<<endl;
        int index = 0;
        while (index < problem_size){
            vector <float> coordinates_in_point (point_size);
            for (int iter = 0; iter < point_size; iter ++){
                cin >> coordinates_in_point[iter];
            }
            initial_points.push_back(coordinates_in_point);
            index++;
        }
        have_initialsymplex =1;
    }
    cout << "Do you know coefficients alpha, betf, gamma?(y/n)" << endl;
    cin >> answer;
    float alpha;
    float beta;
    float gamma;
    bool have_coeff = 0;
    if (answer == 'y' || answer == 'Y'){
        cout << "Input alpha"<< endl;
        cin >> alpha;
        cout << endl <<"Input beta"<< endl;
        cin >> beta;
        cout << endl << "Input gamma"<< endl;
        cin >> gamma;
        have_coeff = 1;
    }
    if (!have_coeff && !have_initialsymplex){
        Nelder_Mead algorithm = Nelder_Mead(problem_size, function_Izom_2d);
        Do_Nelder_Mead(algorithm);
    }
    else if (have_coeff && have_initialsymplex){
        Nelder_Mead algorithm = Nelder_Mead(problem_size,function2_2d,initial_points, alpha, beta, gamma);
        Do_Nelder_Mead(algorithm);
    }
    else if(have_coeff && !have_initialsymplex){
        Nelder_Mead algorithm = Nelder_Mead(problem_size, function2_2d, alpha, beta, gamma);
        Do_Nelder_Mead(algorithm);
    }
    else if(!have_coeff && have_initialsymplex){
        Nelder_Mead algorithm = Nelder_Mead(problem_size, initial_points, function2_2d);
        Do_Nelder_Mead(algorithm);
    }
}
