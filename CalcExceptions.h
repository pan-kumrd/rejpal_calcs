/*
 * CalcExceptions.h
 *
 *  Created on: Feb 21, 2012
 *      Author: pan_kumrd
 */

#ifndef CALCEXCEPTIONS_H_
#define CALCEXCEPTIONS_H_

#include <stdexcept>

class CalcException : public std::runtime_error
{
public:
    explicit CalcException(std::string const& whatMsg) :
        std::runtime_error(whatMsg)
    {}
};

class NonexistenceException : public CalcException
{
public:
    explicit NonexistenceException(std::string const& whatMsg) :
    CalcException(whatMsg)
    {}
};

class InvalidCalc : public CalcException
{
public:
    explicit InvalidCalc(std::string const& whatMsg) :
    CalcException(whatMsg)
    {}
};


#endif /* CALCEXCEPTIONS_H_ */
