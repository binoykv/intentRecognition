/*
 This is a command line tool for intent recognition
*/
#include <iostream>
#include <string.h>
#include <algorithm>
#include <map>
#include <regex>
#include <iterator>
using namespace std;
#define MAXCMDLEN 50
class IntentRecognition
{
private:
	char inputCmd[MAXCMDLEN];
	std::map<std::string,std::string> m_intentList {
		{"UNKNOWN","Unknown command"},
		{"GET WEATHER","What is the weather like today?"},
		{"GET WEATHER CITY","What is the weather like in #CITY today?"},
		{"GET FACT","Tell me an interesting fact."},
	};
	string getIntentValue(string key)
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
	vector<string> split(string &s, char delim = ' ')
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
public:
	string toUpperCase(string s)
	{
		string result;
		for_each(s.begin(),s.end(), [](char & c){
			c = ::toupper(c);
		});
		result = s;
		return result;
	}
	bool start()
	{
		return true;
	}
	string processCommand(string cmd)
	{
		string result;
		string cmdFormatted = toUpperCase(cmd);
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
		return result;
	}

	bool getInputCommand()
	{
		return false;
	}

};
int main()
{
  std::cout<<"##### This is a command line tool for intent recognition #####"<<std::endl;
  
  IntentRecognition obj;
  cout<<obj.processCommand("GET WEATHER Paris")<<endl;
  cout<<obj.processCommand("GET WEATHER Darmstadt City")<<endl;
  cout<<obj.processCommand("GET WEATHER")<<endl;
  cout<<obj.processCommand("GET WEA")<<endl;
  return 1;
}
