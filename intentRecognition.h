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
		/*
		 * Add more commands in the map here and corresponding intent recognition
		 * Implement the pattern identification in  processCmd() method
		 */
	};
	std::vector<std::string> split(std::string &s, char delim = ' ');

	/*
	 * For formatting the input command
	 * @inputCMd --> the string to be formatted
	 * @formattedOuput --> The formatted output
	 * return true if formatting is success,else false
	 * return false for empty inputCmd
	 * The function as of now do the following formatting
	 * 	- Remove additional space at beginning of string, between the words and end of the string as well
	 * 	(Can add additional formatting later)
	 */
	bool formatCmd(std::string inputCmd, std::string &formattedOutput);

	/*
	 * Helper method for converting string to uppercase
	 * @s is the input string to be processed
	 * returns upper case of input
	 */
	std::string toUpperCase(std::string s);

	/*
	 * For taking user input command
	 *  As of now, command is input through command line (getline())
	 */
	bool getInputCommand();

	/*
	 * For displaying the output for user input
	 * As of now, command line out (cout) is implemented
	 */
	void printOutput(std::string outString);
public:
	/*
	 * getIntentValue() is for a getter function for the intent map variable
	 * The function returns the associated value with respect to the key
	 * if no key is available, the function returns value associated with "UNKNOWN" key
	 */
	std::string getIntentValue(std::string key);

	/*
	 * For starting the intent recognition engine
	 * The function takes input command from user(using getInputCommand()), process it and identify the intent and displays it through the printOutput() method
	 *  Returns true for both valid and invalid commands
	 *  Returns false, if user input is exit/close
	 */
	bool start();

	/*
	 * Method for processing the input command and recognizes the associated intent
	 * If command is not recognized, return value equivalent to "UNKNOWN" key
	 */
	std::string processCommand(std::string cmd);
};

#endif /* INTENTRECOGNITION_H_ */
