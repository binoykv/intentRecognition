/*
* intentRecognition.cpp class implementation
*/
#include <iostream>
#include <algorithm>
#include <regex>
#include <iterator>
using namespace std;

#include "intentRecognition.h"

std::string IntentRecognition::getIntentValue(std::string key)
{
	map<string, string>::iterator iter = m_intentList.find(key);
	if(iter == m_intentList.end())
	{
		return m_intentList.at("UNKNOWN");
	}
	else
	{
		return m_intentList.at(key);
	}
}

std::vector<std::string> IntentRecognition::split(std::string &s, char delim)
{
	vector<string> result;
	stringstream ss(s);
	string item;
	while(getline(ss,item,delim))
	{
		result.push_back(item);
	}
	return result;
}

bool IntentRecognition::formatCmd(std::string inputCmd,
		std::string &formattedOutput)
{
	/*
	* For formatting the command
	*/
	if(inputCmd.empty())
		return false;
	for(int i=0;i<inputCmd.length()-1;i++)
	{
		if(i==0)
		{
			// Removing space at beginning of inputCmd
			if(inputCmd[i]==' ')
			{
				inputCmd.erase(i,1);
				i--;
			}
		}
		else
		{
			if((inputCmd[i]==' ') && (inputCmd[i+1]==' '))
			{
				// Removing extra space between characters
				inputCmd.erase(i+1,1);
				i--;
			}

			if(inputCmd[inputCmd.length()-1] == ' ')
			{
				// Removing  spaces at end of string
				inputCmd.erase(inputCmd.length()-1,1);
				i--;
			}
		}

	}
	formattedOutput = inputCmd;
	return true;
}

std::string IntentRecognition::toUpperCase(std::string s)
{
	string result;
	for_each(s.begin(),s.end(), [](char & c){
		c = ::toupper(c);
	});
	result = s;
	return result;
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
	cout<<endl<<"> ";
	bool validCmd = this->getInputCommand();
	string recongizedIntent;
	if(validCmd)
	{
		// The input command is a valid string and no exception in user input
		recongizedIntent = processCommand(m_inputCmd);
	}
	else
	{
		//Exception in user input
		recongizedIntent = getIntentValue("UNKNOWN");
	}

	if((m_inputCmd == "exit") || (m_inputCmd == "Exit") || (m_inputCmd =="close") || (m_inputCmd =="Close"))
		return false;
	printOutput(recongizedIntent);
	return true;
}

std::string IntentRecognition::processCommand(std::string cmd)
{
	string result;
	string upperCaseConverted = toUpperCase(cmd);
	string cmdFormatted;
	if(formatCmd(upperCaseConverted,cmdFormatted))
	{
		if (regex_match (cmdFormatted, regex("(GET)(.*)") ))
		{

			if (regex_match (cmdFormatted, regex("(GET WEATHER)") ))
			{
				// Get Weather command recognized
				result = getIntentValue("GET WEATHER");
			}
			else if (regex_match (cmdFormatted, regex("(GET WEATHER )(.*)") ))
			{
				// Get Weather <City> command recognized
				string intentRequired = getIntentValue("GET WEATHER CITY");
				vector<string> splittedCmd = split(cmd);
				string cityName;
				for(int unsigned i = 0; i<splittedCmd.size();i++)
				{
					if(!(splittedCmd[i].empty()) && (toUpperCase(splittedCmd[i]) !="GET" ) && (toUpperCase(splittedCmd[i]) !="WEATHER"))
					{
						cityName.append(splittedCmd[i]);
						cityName.append(" ");
					}
				}
				cityName.erase(cityName.length()-1,1);
				// Now replace the city name in the intent
				result = regex_replace(intentRequired,regex("#CITY"),cityName);
			}
			else if (regex_match (cmdFormatted, regex("(GET FACT)") ))
			{
				result = getIntentValue("GET FACT");
			}
			else
			{
				result = getIntentValue("UNKNOWN");
			}
		}
		else
		{
			// can implement other intent which doesn't begin with GET
			result = getIntentValue("UNKNOWN");
		}
	}
	else
	{
		result = getIntentValue("UNKNOWN");
	}
	return result;
}

