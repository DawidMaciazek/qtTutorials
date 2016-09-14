#include "expparser.h"


ExpParser::ExpParser(QString qstr)
{
    cstr = qstr.toStdString();
    te_variable vars[] = {{"x", &x}};
    expression = te_compile(cstr.c_str(), vars, 1, &err);
}

ExpParser::~ExpParser()
{
    te_free(expression);
}

double ExpParser::operator ()(double val)
{
    x = val;
    return te_eval(expression);
}
