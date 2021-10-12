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
	bool formatCmd(string inputCmd, string &formattedOutput)
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
	string toUpperCase(string s)
	{
		string result;
		for_each(s.begin(),s.end(), [](char & c){
			c = ::toupper(c);
		});
		result = s;
		return result;
	}
public:
	bool start()
	{
		return true;
	}
	string processCommand(string cmd)
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

	bool getInputCommand()
	{
		return false;
	}

};
int main()
{
  std::cout<<"##### This is a command line tool for intent recognition #####"<<std::endl<<std::endl;
  
  IntentRecognition obj;
  cout<<obj.processCommand("GET WEATHER Paris")<<endl;
  cout<<obj.processCommand("GET WEATHER Darmstadt City")<<endl;
  cout<<obj.processCommand("GET WEATHER")<<endl;
  cout<<obj.processCommand("get weather kochi")<<endl;
  cout<<obj.processCommand(" Get weather ")<<endl;
  cout<<obj.processCommand(" Get  weather  Berlin ")<<endl;
  cout<<obj.processCommand(" gEt   WeAtHer")<<endl;
  cout<<obj.processCommand("Gt weather Berlin")<<endl;
  cout<<obj.processCommand("Get Fact")<<endl;
  cout<<obj.processCommand(" get fact")<<endl;
  cout<<obj.processCommand("get fact 1")<<endl;
  return 1;
}
