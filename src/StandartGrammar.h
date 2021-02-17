#ifndef SGRAMMAR_H
#define SGRAMMAR_H

#include "LSystemGrammar.h"

using namespace std;

class StandartGrammar : public LSystemGrammar
{
    public:
        StandartGrammar(string axiom, vector<string> rul):LSystemGrammar(axiom,rul){}
        void iterate(int);
};

#endif
