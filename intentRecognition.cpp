
#include <iostream>
#include <algorithm>
#include <regex>
#include <iterator>
using namespace std;

#include "intentRecognition.h"

std::string IntentRecognition::getIntentValue(std::string key)
{

}

std::vector<std::string> IntentRecognition::split(std::string &s, char delim)
{


bool IntentRecognition::formatCmd(std::string inputCmd,
		std::string &formattedOutput)
{
	
}

std::string IntentRecognition::toUpperCase(std::string s)
{
	
}

bool IntentRecognition::getInputCommand()
{
	try {
		getline(cin,m_inputCmd);
	}
	catch(...)
	{
		return false;
	}
	return true;
}

void IntentRecognition::printOutput(std::string outString)
{
	cout<<outString<<endl;
}

bool IntentRecognition::start()
{
	
}

std::string IntentRecognition::processCommand(std::string cmd)
{
	
}

