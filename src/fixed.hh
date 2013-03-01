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

#ifndef FIXED_HH
#define FIXED_HH

#include <boost/optional.hpp>
#include "bitnumber_base.hh"

namespace binary_number
{
class Fixed : public Number
{
private:
  size_type bits_m;
  mpz_t bit_mask_m;
protected:
  void create_bit_mask();
  //const mpz_t& bit_mask() const {return bit_mask_m;}

  void interpret_masked();
  std::ostream& print_value_in_base(std::ostream& ost, const BaseValue& base,
				    const mpz_t& print_value) const;
public:
  Fixed(const long& value_, const size_type& bits_);
  Fixed(const unsigned long& value_, const size_type& bits_);
  ~Fixed();
  
  const size_type& bits() const {return bits_m;}
  
  int bit(const size_type& nr) const;
  mpz_class bit_mask() const {return mpz_class{bit_mask_m};}
};

class SignedFixed : public Fixed
{
public:
  SignedFixed(const long& value_=0, const size_type& bits_=1);
  ~SignedFixed(){};

  std::ostream& print(std::ostream& ost) const;
  std::ostream& print_in_base(std::ostream& ost, const BaseValue& base) const;
};

class UnsignedFixed : public Fixed
{
public:
  UnsignedFixed(const unsigned long& value_=0, const size_type& bits_=1)
    :Fixed(value_,bits_){}
  ~UnsignedFixed(){};

  std::ostream& print(std::ostream& ost) const;
  std::ostream& print_in_base(std::ostream& ost, const BaseValue& base) const;
};

void twos_complement_negate(mpz_t& value);

}

#endif
