/*
 * CalcExceptions.h
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
