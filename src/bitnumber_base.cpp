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

#include "bitnumber_base.hh"

namespace binary_number
{

std::ostream& BaseValue::print(std::ostream& ost) const
{
  return ost<<"<"<<base_m<<">";
}


BaseValue Number::default_base_m;

Number::Number(const long& value_, const size_type& bits_)
{
  mpz_init2(value_m,bits_);
  mpz_set_si(value_m,value_);
}

Number::Number(const unsigned long& value_, const size_type& bits_)
{
  mpz_init2(value_m,bits_);
  mpz_set_ui(value_m,value_);
}

Number::~Number()
{
  mpz_clear(value_m);
}
}
