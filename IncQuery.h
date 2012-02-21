/*
 * IncQuery.h
 *
 *  Created on: Feb 21, 2012
 *      Author: pan_kumrd
 */

#ifndef INCQUERY_H_
#define INCQUERY_H_

#include <iostream>
#include <string>

#define OPERATIONS "+-="

#define BIND "wtf"

class IncQuery
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
    IncQuery(std::string query);

    /**
     * Destructor
     */
    virtual ~IncQuery();

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

#endif /* INCQUERY_H_ */
