/*
 * GrubConfigObjectTest.h
 *
 *  Created on: 5 Mar 2012
 *      Author: niall
 */

#ifndef GRUBCONFIGOBJECTTEST_H_
#define GRUBCONFIGOBJECTTEST_H_
#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"

namespace remenu {

class GrubConfigObjectTest {
public:
	GrubConfigObjectTest(){};
	virtual ~GrubConfigObjectTest(){};
	static void runSuite();
	static void testConstructor();
	static void testParseConfig();
	static void testParseMenuEntries();


};

} /* namespace remenu */
#endif /* GRUBCONFIGOBJECTTEST_H_ */
