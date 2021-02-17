#ifndef FILTER_H
#define FILTER_H

#include <string>
#include <vector>
#include <iostream>
#include "LRule.h"

using namespace std;

class Filter
{
    Filter *source;
    string buffer;
    vector<LRule> rules;
    public:
        Filter(Filter* source_, vector<LRule> rules_): source(source_), buffer(""), rules(rules_){}
        Filter(string buffer_, vector<LRule> rules_): source(nullptr), buffer(buffer_), rules(rules_){}
        char getc();
        // ~Filter(){delete source;}
};

#endif
