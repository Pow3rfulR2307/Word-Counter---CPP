#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include <cctype>

void readWord(std::ifstream& file) {

	std::string word;
	std::unordered_map<std::string, int>wordCounter;

	while (file >> word) {

		std::cout << word << " ";

		word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end()); //no punctuation

		for (char& c : word) {
			
			c = std::toupper(c);
		}
		wordCounter[word]++;
	}

	for (const auto& entry : wordCounter) {
	
		std::cout <<" --- " << entry.first << ":" << entry.second << " --- \n";
	}
}

int main()
{
	const char* path = "Caminho//diretorio//arquivo.txt"; //diretório do arquivo.
	std::ifstream inputFile(path);

	if (!inputFile.is_open()) {
	
		std::cout << "Error Opening File\n";

		return 1;
	}

	readWord(inputFile);
	inputFile.close();

	return 0;

}