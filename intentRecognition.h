/*
 * intentRecognition.h
 *
 *  Created on: Oct 13, 2021
 *      Author: Va
 */

#ifndef INTENTRECOGNITION_H_
#define INTENTRECOGNITION_H_

#include <map>
#include <string.h>
#include <vector>
class IntentRecognition
{
private:
	std::string m_inputCmd;
	std::map<std::string,std::string> m_intentList {
		{"UNKNOWN","Unknown command"},
		{"GET WEATHER","What is the weather like today?"},
		{"GET WEATHER CITY","What is the weather like in #CITY today?"},
		{"GET FACT","Tell me an interesting fact."},
	};

	std::string getIntentValue(std::string key);
	std::vector<std::string> split(std::string &s, char delim = ' ');
	bool formatCmd(std::string inputCmd, std::string &formattedOutput);
	std::string toUpperCase(std::string s);
	bool getInputCommand();
	void printOutput(std::string outString);
public:
	bool start();
	std::string processCommand(std::string cmd);
};

#endif /* INTENTRECOGNITION_H_ */
