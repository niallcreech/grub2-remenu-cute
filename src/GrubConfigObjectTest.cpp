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
			ASSERT(obj_keys.find(*it_default_keys) != obj_keys.end());
			++it_default_keys;
		}
	}

}
void GrubConfigObjectTest::testParseConfig() {
	const std::string CFG_FILE = "data/grub.cfg";
	GrubConfigObject obj(CFG_FILE);
	obj.parseConfig();

	// test has 6 menuentry

	const std::map<std::string, std::list<std::string> > & raw_data = obj.getConfigKeys();
	ASSERT(raw_data.size()>0);

	// check menuentries
	{
		const std::string key = GRUB_MENUENTRY_TEXT;
		const std::map<std::string, std::list<std::string> >::const_iterator it_found = raw_data.find(key);
		ASSERT(it_found!=raw_data.end());
		size_t raw_entry_count = raw_data.begin()->second.size();
		ASSERT_EQUAL(6, raw_entry_count);

	}
}

void GrubConfigObjectTest::testParseMenuEntries() {
	const std::string CFG_FILE = "data/grub.cfg";
	GrubConfigObject obj(CFG_FILE);
	obj.parseConfig();

	// test has 6 menuentry

	const std::map<std::string, std::list<std::string> > & entry_data = obj.getConfigEntries();
	ASSERT(entry_data.size()>0);

	// check menuentries
	{
		const std::string key = GRUB_MENUENTRY_TEXT;
		std::map<std::string, std::list<std::string> >::const_iterator it_found = entry_data.find(key);
		ASSERT(it_found!=entry_data.end());
		size_t raw_entry_count = entry_data.begin()->second.size();
		ASSERT_EQUAL(6, raw_entry_count);
		const std::vector<std::string> entries(it_found->second.begin(), it_found->second.end());
		ASSERT_EQUAL("MenuEntryA", entries.at(0));
		ASSERT_EQUAL("MenuEntryB", entries.at(1));
		ASSERT_EQUAL("MenuEntryC", entries.at(2));
		ASSERT_EQUAL("MenuEntryD", entries.at(3));
		ASSERT_EQUAL("MenuEntryE", entries.at(4));
		ASSERT_EQUAL("MenuEntryF", entries.at(5));
	}
}

} /* namespace remenu */
