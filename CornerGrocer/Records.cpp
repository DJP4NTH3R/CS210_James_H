#include "Records.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

// sets the input file name
void Records::setInputFileName(std::string input)
{
	inputFileName = input;
}

// returns the input file name
std::string Records::getInputFileName()
{
	return inputFileName;
}

// allocates a map with all words and their frequencies
void Records::initializeWordFrequency()
{
	// open the input file
	inFS.open(getInputFileName());
	// check if the file is opened successfully
	if (!inFS.is_open()) {
		std::cerr << "Error opening file: " << getInputFileName() << std::endl;
	}

	// read text records from the file
	std::string line;
	while (std::getline(inFS, line)) {
		// Create a stringstream to extract words from each line
		std::istringstream iss(line);

		// extract words from the line and update wordFrequency
		std::string word;
		while (iss >> word) {
			// increment the frequency of the word in the map
			wordFrequency[word]++;
		}
	}

	// close the input file
	inFS.close();

}

// returns the map
std::map<std::string, int> Records::getWordFrequency()
{
	return wordFrequency;
}

// returns the integer value of a specific word in the map
int Records::frequencySearch(std::string input)
{
	// check if the record exists
	if (getWordFrequency().count(input) > 0) {
		// output the frequency as an integer
		return getWordFrequency().at(input);
	}
	else {
		// return zero if we don't find a record
		return 0;
	}
}

// output the frequency of words as a number
void Records::frequencyNum()
{
	//open the output stream to save our data
	outFS.open("frequency.dat");
	for (const auto& pair : getWordFrequency()) {
		std::cout << std::string(13 - pair.first.length(), ' ') << pair.first << ": " << pair.second << std::endl;
		// ensure we have the output file open
		if (outFS.is_open()) {
			// output to file without formatting
			outFS << pair.first << ": " << pair.second << std::endl;
		}
	}
	// close the output file
	outFS.close();
}

// output the frequency of each word as a graph
void Records::frquencyGraph()
{
	for (const auto& pair : getWordFrequency()) {
		std::cout << std::string(13 - pair.first.length(), ' ') << pair.first << ": " << std::string(pair.second, '*') << std::endl;
	}
}
