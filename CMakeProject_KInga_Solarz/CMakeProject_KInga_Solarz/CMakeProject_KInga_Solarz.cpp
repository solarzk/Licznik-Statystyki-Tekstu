// CMakeProject_KInga_Solarz.cpp: definiuje punkt wejścia dla aplikacji.
//

#include "CMakeProject_KInga_Solarz.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

using std::vector;


///////////////////////////////////////////////////////////
// This function allows to count words contained in a given line.
///////////////////////////////////////////////////////////
//		
// INPUT:
//		line – line from a file
//		
// OUTPUT:
//		words – variable containing the number of words 
//		
// REMARKS:
//		lenOfSentence - variable containing the length of the line
//
///////////////////////////////////////////////////////////

auto wordCount(std::string line)
{
    int words = 0;
    int lenOfSentence = line.size();

    for (int i = 0; i < lenOfSentence; i++)
    {
        if (line[i] == ' ')
        {
            words++;
        }
    }

    words = words + 1;

    return words;
}


///////////////////////////////////////////////////////////
// This function allows to count letters contained in a given line.
///////////////////////////////////////////////////////////
//		
// INPUT:
//		line – line from a file
//		
// OUTPUT:
//		letters – variable containing the number of letters 
//		
// REMARKS:
//		lenOfSentence - variable containing the length of the line
//
///////////////////////////////////////////////////////////

auto letterCount(std::string line)
{
    int letters = 0;
    int lenOfSentence = line.size();

    for (int i = 0; i < lenOfSentence; i++)
    {
        if (isalpha(line[i]))
        {
            letters++;
        }
    }

    return letters;
}


///////////////////////////////////////////////////////////
// This function allows to count lines of text contained in a given file.
///////////////////////////////////////////////////////////
//		
// INPUT:
//		fileName – name of a file
//		
// OUTPUT:
//		values – vector containing the values of the calculated statistics 
//		
// REMARKS:
//		lineCounter - variable containing the number of lines
//		wordCounter - variable containing the number of words
//		letterCounter - variable containing the number of letters
//
///////////////////////////////////////////////////////////


auto readFile(std::string fileName)
{
    std::ifstream file;
    file.open(fileName, std::ios::in);
    if (!file.good())
        cout << "Failed to open the file" << endl;

    std::string line;

    int lineCounter = 0, wordCounter = 0, letterCounter = 0;

    if (file.good() == true)
    {
        while (!file.eof())
        {
            getline(file, line);
            lineCounter++;
            wordCounter += wordCount(line);
            letterCounter += letterCount(line);
        }
        file.close();
    }

    vector<int> values;
    values.push_back(lineCounter);
    values.push_back(wordCounter);
    values.push_back(letterCounter);

    return values;
}

int main()
{
    vector<int> values = {};

    std::string fileName;

    cout << "Please enter a valid file name (filetype .txt)\n";

    cin >> fileName;

    values = readFile(fileName);

    cout << "\nThis file contains:\n\tLines:\t" << values[0] << "\n\tWords:\t" << values[1] << "\n\tLetters:\t" << values[2];

    return 0;
}
