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

#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/CompilerOutputter.h>
#include "constructor.hh"
#include "message/message.hh"

int main()
{
  CppUnit::TextUi::TestRunner runner;
  //CppUnit::TestFactoryRegistry& registry = CppUnit::TestFactoryRegistry::getRegistry();

  
  runner.addTest(ConstructorTest::suite());
  runner.setOutputter(new CppUnit::CompilerOutputter(&runner.result(),message::info));
  return !runner.run();
}
