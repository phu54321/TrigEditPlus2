#include "catch.hpp"
#include <string>

std::string DecodeCondition(const char* ptr);

TEST_CASE("Decoding \"Always\" condition", "[decoder]") {
	const char alwaysCond[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x22\0\0\0\0";
	REQUIRE(DecodeCondition(alwaysCond) == "Always();");
}


TEST_CASE("Decoding \"Never\" condition", "[decoder]") {
	const char neverCond[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x23\0\0\0\0";
	REQUIRE(DecodeCondition(neverCond) == "Never();");
}
