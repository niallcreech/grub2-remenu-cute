/*
 * GrubScriptObjectTest.h
 *
 *  Created on: 6 Mar 2012
 *      Author: niall
 */

#ifndef GRUBSCRIPTOBJECTTEST_H_
#define GRUBSCRIPTOBJECTTEST_H_
#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
namespace remenu {

class GrubScriptObjectTest {
public:
	GrubScriptObjectTest(){};
	virtual ~GrubScriptObjectTest(){};

	static  void runSuite();
	static void testGetSetClearRename();
};

} /* namespace remenu */
#endif /* GRUBSCRIPTOBJECTTEST_H_ */
