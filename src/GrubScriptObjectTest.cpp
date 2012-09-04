/*
 * GrubScriptObjectTest.cpp
 *
 *  Created on: 6 Mar 2012
 *      Author: niall
 */

#include "GrubScriptObjectTest.h"
#include "GrubScriptObject.h"

namespace remenu {

void GrubScriptObjectTest::runSuite() {
	cute::suite s;
	s.push_back(CUTE(GrubScriptObjectTest::testGetSetClearRename));
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "GrubScriptObjectTest");
}

void GrubScriptObjectTest::testGetSetClearRename() {
	GrubScriptObject obj("");
	const std::string MENU1 = "MenuEntry1";
	const std::string RENAME1 = "Renamed1";
	const std::string MENU2 = "MenuEntry2";
	const std::string RENAME2 = "Renamed2";
	const std::string MENU3 = "MenuEntry3";
	const std::string RENAME3 = "Renamed3";
	const std::pair<std::string, std::string> EMPTY("", "");

	// test adding 3 renames
	{
		obj.setRename(MENU1, RENAME1);
		obj.setRename(MENU2, RENAME2);
		obj.setRename(MENU3, RENAME3);

		ASSERT_EQUAL(3, obj.getRenames().size());
	}

	// test names are what we expect
	{
		ASSERT_EQUAL(MENU1, obj.getRename(MENU1).first);
		ASSERT_EQUAL(RENAME1, obj.getRename(MENU1).second);
		ASSERT_EQUAL(MENU2, obj.getRename(MENU2).first);
		ASSERT_EQUAL(RENAME2, obj.getRename(MENU2).second);
		ASSERT_EQUAL(MENU3, obj.getRename(MENU3).first);
		ASSERT_EQUAL(RENAME3, obj.getRename(MENU3).second);
		ASSERT_EQUAL(EMPTY, obj.getRename("no"));
	}

	// test clearing rename
	{
		obj.clearRename(MENU2);
		ASSERT_EQUAL(2, obj.getRenames().size());
		// one that doesnt exist
		obj.clearRename("no");
		ASSERT_EQUAL(2, obj.getRenames().size());

		obj.clearRename(MENU1);
		ASSERT_EQUAL(1, obj.getRenames().size());

		obj.clearRename(MENU3);
		ASSERT_EQUAL(0, obj.getRenames().size());

		//  remove one from empty
		obj.clearRename(MENU3);
		ASSERT_EQUAL(0, obj.getRenames().size());
	}

	// check clear
	{
		obj.setRename(MENU1, RENAME1);
		obj.clear();
		ASSERT_EQUAL(0, obj.getRenames().size());
	}

}
} /* namespace remenu */
