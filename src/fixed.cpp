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

#include "fixed.hh"

namespace binary_number
{

// -5 111011

Fixed::Fixed(const long& value_, const size_type& bits_)
  :Number(value_,bits_),bits_m(bits_)
{
  create_bit_mask();
  mpz_and(value(),value(),bit_mask_m);
}

Fixed::Fixed(const unsigned long& value_, const size_type& bits_)
  :Number(value_,bits_),bits_m(bits_)
{
  create_bit_mask();
  mpz_and(value(),value(),bit_mask_m);
}


void Fixed::create_bit_mask()
{
  mpz_init(bit_mask_m);
  mpz_setbit(bit_mask_m,bits_m);
  mpz_sub_ui(bit_mask_m,bit_mask_m,1);
}

void Fixed::interpret_masked()
{
  if(mpz_tstbit(value(),bits_m-1))
  {
    mpz_t sub_val;
    mpz_init(sub_val);
    mpz_setbit(sub_val,bits_m);
    mpz_sub(value(),value(),sub_val);
    mpz_clear(sub_val);
  }
}


Fixed::~Fixed()
{
  mpz_clear(bit_mask_m);
}

int Fixed::bit(const size_type& nr) const
{
  return mpz_tstbit(value(),nr);
}


std::ostream& Fixed::print_value_in_base(std::ostream& ost, const BaseValue& base,
					 const mpz_t& print_value) const
{

  mpz_t masked_value;
  mpz_init(masked_value);
  
  mpz_and(masked_value,print_value,bit_mask_m);

  const std::size_t chars = mpz_sizeinbase(masked_value,base);
  const std::size_t mask_chars = mpz_sizeinbase(bit_mask_m,base);
  
  char* value_string = new char[chars+1];
  
  mpz_get_str(value_string,base,masked_value);

  std::string leading_zeros;
  
  if(sign() >= 0)
  {
    std::size_t num_leading = mask_chars - chars;
    leading_zeros = std::string(num_leading,'0');
  }
  
  ost<<leading_zeros<<value_string;

  delete[] value_string;

  mpz_clear(masked_value);
  
  return ost;
}


SignedFixed::SignedFixed(const long& value_, const size_type& bits_)
  :Fixed(value_,bits_)
{
  interpret_masked();
}


std::ostream& SignedFixed::print(std::ostream& ost) const
{
  return print_in_base(ost,default_base());
}

std::ostream& SignedFixed::print_in_base(std::ostream& ost, const BaseValue& base) const
{
  ost<<bits()<<base<<"s";

  Fixed::print_value_in_base(ost,base,value());

  return ost;
}

std::ostream& UnsignedFixed::print(std::ostream& ost) const
{
  return print_in_base(ost,default_base());
}

std::ostream& UnsignedFixed::print_in_base(std::ostream& ost, const BaseValue& base) const
{
  ost<<bits()<<base<<"u";

  assert(sign() >= 0);

  Fixed::print_value_in_base(ost,base,value());
  
  return ost;
}

//! Make a value its twos complement negation 
/*! 
  This works since GMP does all logical operations as if the 
  numbers where in twos complement representation
  \param value value is the twos complement negation
*/
void twos_complement_negate(mpz_t& value)
{
  mpz_t zero;
  mpz_init_set_ui(zero,0);
  mpz_ior(value,value,zero);
}

}
