/*
* The class that produces the development
* of the lsystem in accordance with its rules.
*/

#ifndef LSGRAMMAR_H
#define LSGRAMMAR_H

#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

#include "LRule.h"
#include "Filter.h"

using namespace std;

class LSystemGrammar
{
    public:
        LSystemGrammar(string, vector<string>);
        Filter* getResult();
    protected:
        Filter *source; // source of chars
        vector<LRule> rules; // rules of the lsystem
};

#endif
