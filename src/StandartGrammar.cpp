#include "StandartGrammar.h"

void StandartGrammar::iterate(const int iterations = 1)
{
    for (unsigned int i = 0; i < iterations-1; ++i)
        source = new Filter(source, rules);
}
