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

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/SourceLine.h>
#include "bitnumber2/fixed.hh"

class ConstructorTest : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE(ConstructorTest);
  CPPUNIT_TEST(signed_fixed_default);
  CPPUNIT_TEST(unsigned_fixed_default);
  CPPUNIT_TEST(signed_fixed);
  CPPUNIT_TEST(unsigned_fixed);
  CPPUNIT_TEST_SUITE_END();
private:
  void test_value_si(const binary_number::Fixed& value, const binary_number::Fixed::size_type& ref_bits, 
		     const long& ref_value, const CppUnit::SourceLine& line);
  void test_value_ui(const binary_number::Fixed& value, const binary_number::Fixed::size_type& ref_bits, 
		     const unsigned long& ref_value, const CppUnit::SourceLine& line);
public:
  void signed_fixed_default();
  void unsigned_fixed_default();
  void signed_fixed();
  void unsigned_fixed();
};
