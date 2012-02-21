/*
 * IncQuery.cpp
 *
 *  Created on: Feb 21, 2012
 *      Author: pan_kumrd
 */

#include <iostream>
#include <string>

#include "IncQuery.h"

using std::string;

IncQuery::IncQuery(string query)
{
    const string ops = OPERATIONS;
    size_t operatorPos, opIt = 0;

    if (query == BIND)
    {
        //TODO: call random calc
    }

    for (opIt = 0; opIt != ops.length(); opIt++)
    {
        operatorPos = 0;

        if ((operatorPos = query.find(ops[opIt])) != string::npos)
        {
            break;
        }
    }



}

string IncQuery::getCalc() const
{
    return m_calc;
}

string IncQuery::getCalcName() const
{
    return m_calcName;
}

char IncQuery::getCommand() const
{
    return m_command;
}

void IncQuery::setCalc(string m_calc)
{
    this->m_calc = m_calc;
}

void IncQuery::setCalcName(string m_calcName)
{
    this->m_calcName = m_calcName;
}

void IncQuery::setCommand(char m_command)
{
    this->m_command = m_command;
}

IncQuery::~IncQuery()
{
    // TODO Auto-generated destructor stub
}

