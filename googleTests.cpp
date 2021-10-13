/*
* googleTest.cpp --> Google Test case definitions for intentRecognition class implementation
*/
#include <src/gtest-all.cc>
#include <gtest/gtest.h>
#include "intentRecognition.h"
TEST(Get_Weather_Test,TestCases)
{
	IntentRecognition testObj;
	EXPECT_EQ("What is the weather like today?",testObj.processCommand("Get Weather"));
	EXPECT_EQ("What is the weather like today?",testObj.processCommand("GET WEATHER"));
	EXPECT_EQ("What is the weather like today?",testObj.processCommand("gEt wEaTher"));
	EXPECT_EQ("What is the weather like today?",testObj.processCommand("Get  Weather "));
	EXPECT_EQ("What is the weather like today?",testObj.processCommand("  Get  Weather "));
}
TEST(Get_Weather_City_Test,TestCases)
{
	IntentRecognition testObj;
	EXPECT_EQ("What is the weather like in Paris today?",testObj.processCommand("Get Weather Paris"));
	EXPECT_EQ("What is the weather like in Berlin today?",testObj.processCommand("GET WEATHER Berlin"));
	EXPECT_EQ("What is the weather like in Munich today?",testObj.processCommand("gEt wEaTher Munich"));
	EXPECT_EQ("What is the weather like in Stuttgart today?",testObj.processCommand("Get  Weather  Stuttgart "));
	EXPECT_EQ("What is the weather like in Koln City today?",testObj.processCommand("  Get  Weather Koln City"));
	EXPECT_EQ("What is the weather like in New York City today?",testObj.processCommand("Get Weather New York City"));
}
TEST(Get_Fact_Test,TestCases)
{
	IntentRecognition testObj;
	EXPECT_EQ("Tell me an interesting fact.",testObj.processCommand("Get Fact"));
	EXPECT_EQ("Tell me an interesting fact.",testObj.processCommand("GET FACT"));
	EXPECT_EQ("Tell me an interesting fact.",testObj.processCommand("gEt fACt"));
	EXPECT_EQ("Tell me an interesting fact.",testObj.processCommand("Get  Fact "));
	EXPECT_EQ("Tell me an interesting fact.",testObj.processCommand("  Get  Fact "));
}

TEST(Unknown_Cmds,TestCases)
{
	IntentRecognition testObj;
	EXPECT_EQ("Unknown command",testObj.processCommand(""));
	EXPECT_EQ("Unknown command",testObj.processCommand("Get"));
	EXPECT_EQ("Unknown command",testObj.processCommand("Get Wea"));
	EXPECT_EQ("Unknown command",testObj.processCommand("Weather"));
	EXPECT_EQ("Unknown command",testObj.processCommand(" "));
}
int main(int argc, char** argv)
{
	  ::testing::InitGoogleTest(&argc, argv);
	  return RUN_ALL_TESTS();
}


