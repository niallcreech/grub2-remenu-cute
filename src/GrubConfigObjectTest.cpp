/*
 * GrubConfigObjectTest.cpp
 *
 *  Created on: 5 Mar 2012
 *      Author: niall
 */

#include "GrubConfigObjectTest.h"
#include "GrubConfigObject.h"
#include "GrubScriptObject.h"
#include "MainDefs.h"
#include <list>
#include <string>

namespace remenu {

void GrubConfigObjectTest::runSuite() {
	cute::suite s;
	s.push_back(CUTE(GrubConfigObjectTest::testConstructor));
	s.push_back(CUTE(GrubConfigObjectTest::testParseConfig));
	s.push_back(CUTE(GrubConfigObjectTest::testParseMenuEntries));
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "GrubConfigObjectTest");
}

void GrubConfigObjectTest::testConstructor() {
	//contains 6 entries
	const std::string CFG_FILE = "data/grub.cfg";
	const size_t ENTRY_KEYS_SZ = 1;
	std::list<std::string> default_keys;
	default_keys.push_back(GRUB_MENUENTRY_TEXT);
	GrubConfigObject obj(CFG_FILE);
	ASSERT_EQUAL(ENTRY_KEYS_SZ, obj.getConfigKeys().size());
	// forall in default_keys
	{
		const std::map<std::string, std::list<std::string> > & obj_keys = obj.getConfigKeys();
		std::list<std::string>::const_iterator it_default_keys = default_keys.begin();
		const std::list<std::string>::const_iterator it_default_keys_end = default_keys.end();
		while (it_default_keys != it_default_keys_end) {
			ASSERT(obj_keys.find(*it_default_keys) != obj_keys.end() );
			++it_default_keys;
		}
	}

}
void GrubConfigObjectTest::testParseConfig() {
	ASSERTM("TODO", false);
}
void GrubConfigObjectTest::testParseMenuEntries() {
	ASSERTM("TODO", false);
}

} /* namespace remenu */
