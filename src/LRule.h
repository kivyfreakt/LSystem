#ifndef LRULE_H
#define LRULE_H

#include <string>

using namespace std;

// change it!!!

struct LRule
{
    LRule(string var, string rul):variable(var), rule(rul){}
    LRule(string var, string rul, float prob):variable(var), rule(rul), probability(prob){}
    string variable;
    string rule;
    float probability;
};

#endif
