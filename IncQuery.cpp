/*
 * IncQuery.cpp
 *
 * Author: Michael Ruml <info@michaelruml.cz>
 *
 * This file is part of rejpal_calcs.
 *
 * rejpal_calcs is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * rejpal_calcs is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with rejpal_calcs.  If not, see <http://www.gnu.org/licenses/>.
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

