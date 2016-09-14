#ifndef EXPPARSER_H
#define EXPPARSER_H

#include <QString>
#include <string>

#include "tinyexpr.h"

class ExpParser
{
public:
    ExpParser(QString qstr);
    ~ExpParser();

    double operator ()(double val);

private:
    int err;
    double x;
    std::string cstr;
    te_expr *expression;

};

#endif // EXPPARSER_H
