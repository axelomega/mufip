// Copyright © 2013 Per Karlström

//This file is part of the Multiprecision Fixed Point Number Library
//(MuFiP).

//MuFiP is free software: you can redistribute it and/or modify it under
//the terms of the GNU General Public License as published by the Free
//Software Foundation, either version 3 of the License, or (at your
//option) any later version.

//MuFiP is distributed in the hope that it will be useful, but WITHOUT
//ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
//FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
//for more details.

//You should have received a copy of the GNU General Public License
//along with MuFiP.  If not, see <http://www.gnu.org/licenses/>.

#ifndef BITNUMBER_BASE_HH
#define BITNUMBER_BASE_HH

#include "policies/policies.hh"
#include <gmpxx.h>

namespace binary_number
{

class BaseValue: public policy::OutStreamable
{
private:
  unsigned int base_m;
public:
  BaseValue(const unsigned int& base_=2):base_m(base_){}
  std::ostream& print(std::ostream& ost) const;

  operator unsigned int() const {return base_m;}
};

class Number: public policy::OutStreamable
{
public:
  typedef std::size_t size_type;
private:
  mpz_t value_m;
  static BaseValue default_base_m;
protected:
  mpz_t& value(){return value_m;}
  const mpz_t& value() const {return value_m;}
  int sign() const {return mpz_sgn(value_m);}
  Number(const long& value_, const size_type& bits_);
  Number(const unsigned long& value_, const size_type& bits_);
public:
  virtual ~Number()=0;

  virtual const size_type& bits() const=0;
  mpz_class raw_data() const {return mpz_class{value_m};}
  
  static void default_base(const BaseValue& default_base){default_base_m = default_base;}
  static const BaseValue& default_base(){return default_base_m;}
  virtual std::ostream& print_in_base(std::ostream& ost,const BaseValue& base) const=0;   
};
}

#endif
