//Lauren White - Project 2
#include "DictionaryReader.h"
#include <fstream>

//Default constructor for the dictionary
DictionaryReader::DictionaryReader(const string& filePath)
{
    //If there is no data in the file, output an error message and exit the function
    if (!readFile(filePath)) 
    {
          cout << "Error: No data in the file." << endl;

          return;
    }
}

//Get method for the dictionary data
  vector<string> DictionaryReader::getDictionary() const 
  {
    return dictionary;
  }

//Read in the data from the file to the dictionary
bool DictionaryReader::readFile(const string& filePath)
{
    string line;
    ifstream file(filePath);

    //If the file doesn't open, output an error message and return false
    if (!file.is_open()) 
    {
        cout << "Error opening the file." << endl;
        return false;
    }

    //While there is data in the file, add it to the dictionary vector
    while (getline(file, line))
    {
        //Use push_back to add to the end of the vector
        dictionary.push_back(line);
    }

    file.close();
    return true;
}