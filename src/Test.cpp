#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"

#include "GrubConfigObjectTest.h"
#include "GrubScriptObjectTest.h"

int main(){
    remenu::GrubConfigObjectTest::runSuite();
    remenu::GrubScriptObjectTest::runSuite();
    return 0;
}



