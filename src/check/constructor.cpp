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

#include <cppunit/Asserter.h>
#include <boost/lexical_cast.hpp>
#include "constructor.hh"
#include <iostream>
#include <limits>
#include <sstream>
#include "bitnumber2/fixed.hh"

using namespace binary_number;


void ConstructorTest::test_value_si(const Fixed& value, const Fixed::size_type& ref_bits, 
				    const long& ref_value, const CppUnit::SourceLine& line)
{
  if(value.bits() != ref_bits)
  {
    CppUnit::Asserter::failNotEqual(boost::lexical_cast<std::string>(ref_bits),
				    boost::lexical_cast<std::string>(value.bits()),
				    line);
  }
  if(value.raw_data() != mpz_class{ref_value})
  {
    CppUnit::Asserter::failNotEqual(boost::lexical_cast<std::string>(ref_value),
				    value.raw_data().get_str(),
				    line);
  }
}

void ConstructorTest::test_value_ui(const Fixed& value, const Fixed::size_type& ref_bits, 
				    const unsigned long& ref_value, const CppUnit::SourceLine& line)
{
  if(value.bits() != ref_bits)
  {
    CppUnit::Asserter::failNotEqual(boost::lexical_cast<std::string>(ref_bits),
				    boost::lexical_cast<std::string>(value.bits()),
				    line);
  }
  if(value.raw_data() != mpz_class{ref_value})
  {
    CppUnit::Asserter::failNotEqual(boost::lexical_cast<std::string>(ref_value),
				    value.raw_data().get_str(),
				    line);
  }
}


#define CPPUNIT_ASSERT_VALUE_BITS_S(tested,ref_value,ref_bits) \
test_value_si(tested,ref_bits,ref_value,CPPUNIT_SOURCELINE())

#define CPPUNIT_ASSERT_VALUE_BITS_U(tested,ref_value,ref_bits) \
test_value_ui(tested,ref_bits,ref_value,CPPUNIT_SOURCELINE())


void ConstructorTest::signed_fixed_default()
{
  CPPUNIT_ASSERT_VALUE_BITS_S(SignedFixed(),0,1);
}

void ConstructorTest::unsigned_fixed_default()
{
  CPPUNIT_ASSERT_VALUE_BITS_U(UnsignedFixed(),0,1);
}
void ConstructorTest::signed_fixed()
{
  CPPUNIT_ASSERT_VALUE_BITS_S(SignedFixed(3,3),3,3);
  CPPUNIT_ASSERT_VALUE_BITS_S(SignedFixed(3,2),-1,2);

  CPPUNIT_ASSERT_VALUE_BITS_S(SignedFixed(std::numeric_limits<long>::max(),sizeof(long)*8),std::numeric_limits<long>::max(),sizeof(long)*8);
  CPPUNIT_ASSERT_VALUE_BITS_S(SignedFixed(std::numeric_limits<long>::min(),sizeof(long)*8),std::numeric_limits<long>::min(),sizeof(long)*8);
}

void ConstructorTest::unsigned_fixed()
{
  CPPUNIT_ASSERT_VALUE_BITS_U(UnsignedFixed(3,3),3,3);
  CPPUNIT_ASSERT_VALUE_BITS_U(UnsignedFixed(3,2),3,2);

  CPPUNIT_ASSERT_VALUE_BITS_U(UnsignedFixed(std::numeric_limits<unsigned long>::max(),sizeof(unsigned long)*8),std::numeric_limits<unsigned long>::max(),sizeof(unsigned long)*8);
}


CPPUNIT_TEST_SUITE_REGISTRATION(ConstructorTest);
