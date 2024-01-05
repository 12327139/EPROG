#ifndef VECTOR_H
#define VECTOR_H

#include<vector>
#include<string>

// aus Skriptum, Abschnitt 49
class Vector {
private:
    std::vector<double> coefficients;
public:
    Vector(int dim = 0, double init = 0);
    double& get(int k);
    int size(); 
    std::string to_string();
};

#endif