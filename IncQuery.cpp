/*
 * IncQuery.cpp
 *
 *  Created on: Feb 21, 2012
 *      Author: pan_kumrd
 */

#include <iostream>
#include <string>
#include <exception>

#include "IncQuery.h"
#include "CalcExceptions.h"

using std::string;

IncQuery::IncQuery(string query)
{
    m_calc.empty();
    m_calcName.empty();
    m_command = 0;

    const string ops = OPERATIONS;
    size_t operatorPos = 0, opIt = 0;

    try
    {

        // If the given string does not start with bind
        if (query.compare(0, (bind.length()), bind) != 0)
        {
            std::cout << "Invalid query" << std::endl;
            return;
        }

        // If query contained only bind
        if (query == bind)
            return;
        else
            // If it conatins something else, erase the bind
            query.erase(0, (bind.length() + 1));

        // Look for an operator
        for (opIt = 0; opIt != ops.length(); opIt++)
        {
            operatorPos = 0;

            if ((operatorPos = query.find(ops[opIt])) != string::npos)
            {

                if ((query[operatorPos - 1] != ' ')
                        || (query[operatorPos + 1] != ' '))
                {
                    std::cout << "Invalid query";
                    return;
                }

                m_command = query[operatorPos];

                break;
            }
        }

        /* If there is no operator, the the whole query is
         * just a calc name */
        if (!m_command)
        {
            operatorPos = query.length();
        }
        else
        {

            // Copy the calc body
            m_calc.append(query, operatorPos + 2, (query.length() - 1));
        }

        // Copy the calc name
        m_calcName.append(query, 0, operatorPos);

    } catch (CalcException &error)
    {
        std::cerr << error.what();
    }

    return;
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
}

