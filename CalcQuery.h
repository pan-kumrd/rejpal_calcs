/*
 * IncQuery.h
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

#ifndef CALCQUERY_H_
#define CALCQUERY_H_

#include <iostream>
#include <string>

#define OPERATIONS "+-="

const std::string bind = "wtf";

class CalcQuery
{
    /**
     * Stores the name of the given calc
     */
    std::string m_calcName;

    /**
     * Stores the operation symbol
     */
    char m_command;

    /**
     * Stores calc body
     */
    std::string m_calc;

public:
    /**
     * Constructor
     */
    CalcQuery(std::string query);

    /**
     * Destructor
     */
    virtual ~CalcQuery();

    /**
     * getters
     */
    std::string getCalc() const;
    std::string getCalcName() const;
    char getCommand() const;

    /**
     * setters
     */
    void setCalc(std::string m_calc);
    void setCalcName(std::string m_calcName);
    void setCommand(char m_command);
};

#endif /* CALCQUERY_H_ */
