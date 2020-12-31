#include "Filter.h"

char Filter :: getc()
{
    while(buffer.empty())
    {
        if (source == nullptr)
            return -1;
    	char c = source->getc();
    	for (auto r : rules)
            if (r.variable[0] == c)
                buffer += r.rule;
        if (buffer.empty())
            buffer += c;
    }
    char b = buffer[0];
    buffer.erase(0, 1);
    return b;
}
