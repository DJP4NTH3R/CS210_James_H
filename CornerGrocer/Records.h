#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

class Records
{
public:
	void setInputFileName(std::string input);
	std::string getInputFileName();
	void initializeWordFrequency();
	std::map<std::string, int> getWordFrequency();
	int frequencySearch(std::string input);
	void frequencyNum();
	void frquencyGraph();
private:
	std::ifstream inFS;
	std::ofstream outFS;
	std::string inputFileName;
	std::map<std::string, int> wordFrequency;

};

