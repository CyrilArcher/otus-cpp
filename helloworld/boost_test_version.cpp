#define BOOST_TEST_MODULE boost_test_version

#include "version.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(boost_test_version)

BOOST_AUTO_TEST_CASE(boost_test_valid_version)
{
    BOOST_CHECK(PROJECT_VERSION > 0);
}

}
