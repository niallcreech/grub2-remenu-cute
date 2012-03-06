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
	s.push_back(CUTE(GrubScriptObjectTest::testGetSetClearRenameMenu));
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "GrubScriptObjectTest");
}

void GrubScriptObjectTest::testGetSetClearRenameMenu() {
	GrubScriptObject obj;
	const std::string MENU1 = "MenuEntry1";
	const std::string RENAME1 = "Renamed1";
	const std::string MENU2 = "MenuEntry2";
	const std::string RENAME2 = "Renamed2";
	const std::string MENU3 = "MenuEntry3";
	const std::string RENAME3 = "Renamed3";
	const std::pair<std::string, std::string> EMPTY("", "");

	// test adding 3 renames
	{
		obj.setRenameMenu(MENU1, RENAME1);
		obj.setRenameMenu(MENU2, RENAME2);
		obj.setRenameMenu(MENU3, RENAME3);

		ASSERT_EQUAL(3, obj.getMenuRenames().size());
	}

	// test names are what we expect
	{
		ASSERT_EQUAL(MENU1, obj.getRenameMenu(MENU1).first);
		ASSERT_EQUAL(RENAME1, obj.getRenameMenu(MENU1).second);
		ASSERT_EQUAL(MENU2, obj.getRenameMenu(MENU2).first);
		ASSERT_EQUAL(RENAME2, obj.getRenameMenu(MENU2).second);
		ASSERT_EQUAL(MENU3, obj.getRenameMenu(MENU3).first);
		ASSERT_EQUAL(RENAME3, obj.getRenameMenu(MENU3).second);
		ASSERT_EQUAL(EMPTY, obj.getRenameMenu("no"));
	}

	// test clearing rename
	{
		obj.clearRenameMenu(MENU2);
		ASSERT_EQUAL(2, obj.getMenuRenames().size());
		// one that doesnt exist
		obj.clearRenameMenu("no");
		ASSERT_EQUAL(2, obj.getMenuRenames().size());

		obj.clearRenameMenu(MENU1);
		ASSERT_EQUAL(1, obj.getMenuRenames().size());

		obj.clearRenameMenu(MENU3);
		ASSERT_EQUAL(0, obj.getMenuRenames().size());

		//  remove one from empty
		obj.clearRenameMenu(MENU3);
		ASSERT_EQUAL(0, obj.getMenuRenames().size());
	}

	// check clear
	{
		obj.setRenameMenu(MENU1, RENAME1);
		obj.clear();
		ASSERT_EQUAL(0, obj.getMenuRenames().size());
	}

}
} /* namespace remenu */
