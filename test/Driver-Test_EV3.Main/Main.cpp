#include <iostream>

#include "../../src/Thread/Thread.hpp"
#include "../Suite/UnitTestSuite.hpp"
#include "AsservDriverTest.hpp"
#include "ServoDriverTest.hpp"
#include "SensorDriverTest.hpp"
#include "CCAx12TeensyDriverTest.hpp"

using namespace std;

int main() {
    //utils::set_realtime_priority(); //priority MAX 99

    cout << "!!!Hello TEST World!!!" << endl; // prints !!!Hello World!!!

//    test::CCAx12TeensyDriverTest *cc = new test::CCAx12TeensyDriverTest();
//    cc->testSet();

    UnitTestSuite suite;
    suite.addTest(new test::CCAx12TeensyDriverTest());
    //suite.addTest(new test::LedDriverTest());
    //suite.addTest(new test::LcdDriverTest());
    suite.addTest(new test::SensorDriverTest());
    //suite.addTest(new test::AsservDriverTest());
    //suite.addTest(new test::SoundDriverTest());
    //suite.addTest(new test::ServoDriverTest());
    //sleep(2);
    suite.run();

    //Assert/fail
    return 0;
}
