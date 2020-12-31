#include "LSystemGrammar.h"

LSystemGrammar::LSystemGrammar(string axiom, vector<string> rul)
{
    for (auto r : rul)
    {
        auto pos1 = r.find(" => ");
        auto pos2 = r.find(" (");
        auto pos3 = r.find(")");
        if (pos1 != -1 && pos2 != -1)
        {
          string p = r.substr(pos2+3, pos3);
          LRule n(r.substr(0,pos1), r.substr(pos1+4, pos2 - pos1 - 4),stof(p));
          rules.push_back(n);
        }
        else
        {
            if (pos1 != -1)
            {
                LRule n(r.substr(0,pos1), r.substr(pos1+4));
                rules.push_back(n);
            }
        }
    }
    source = new Filter(axiom, rules);
}

Filter* LSystemGrammar::getResult()
{
    return source;
}
