#include "All Functions.h"


int wordCounter(std::string fileName)
{
    int numberOfWords = 0;
    char word[100];
    std::ifstream READ(fileName);
    while (READ >> word)
    {
        numberOfWords++;
    }
    READ.close();
    return numberOfWords;
}

void readText(std::string &document, std::string fileName)
{
    std::ifstream READ(fileName);
    std::string line;
    while (getline(READ, line))
    {
        document += line + "\n";
    }
    READ.close();
}


void tokenizeText(std::vector<std::string>& document, std::string fileName)
{
    std::ifstream READ(fileName);
    int elements = wordCounter(fileName);
    document.resize(elements);
    char word[100];
    int index = 0;
    while (READ >> word)
    {
        document[index] = word;
        index++;
    }
    READ.close();
}

void cloningDocument(std::string duplicateFile, std::string originalFile)
{
    std::string line;
    std::ifstream inputFile(originalFile);
    std::ofstream outputFile(duplicateFile);
    if (inputFile && outputFile)
    {
        while (getline(inputFile, line))
        {
            outputFile << line << "\n";
        }
    }
    inputFile.close();
    outputFile.close();
}

void censoringData(std::string censoredDocument, std::vector<std::string> uncompletedDocument)
{
    std::ofstream writeCensoredElements("./text_files/output/Censored Elements.txt");
    std::ofstream writeCensoredFile("./text_files/output/Censored Document.txt");
    int textStartingPoint = 0, censoringStartingPoint, censoringEndingPoint;
    for (int index = 0; index < uncompletedDocument.size()-1; index++)
    {
        if (uncompletedDocument[index][0] == '.')
        {
            censoringStartingPoint = KMPSearch(uncompletedDocument[index-1], censoredDocument, textStartingPoint) + (uncompletedDocument[index-1]).size() + 1;
            censoringEndingPoint = KMPSearch(uncompletedDocument[index + 1], censoredDocument, textStartingPoint)-1;
            while (abs(censoringEndingPoint - censoringStartingPoint) > 30)
            {
                if (censoringStartingPoint > censoringEndingPoint) censoringEndingPoint = KMPSearch(uncompletedDocument[index + 1], censoredDocument, textStartingPoint + 5)-1;
                censoringStartingPoint = KMPSearch(uncompletedDocument[index - 1], censoredDocument, textStartingPoint+5) + (uncompletedDocument[index - 1]).size() + 1;
                textStartingPoint = censoringStartingPoint;
            }
            if (censoredDocument[censoringStartingPoint] != '.')
            {
                for (int contor = censoringStartingPoint; contor < censoringEndingPoint; contor++)
                {
                    writeCensoredElements << censoredDocument[contor];
                    if (!(contor == censoringEndingPoint - 1 && censoredDocument[contor] == ',')) censoredDocument[contor] = '#';
                }
                writeCensoredElements << "\n";


                textStartingPoint = censoringStartingPoint;
            }
        }
    }
    writeCensoredElements.close();
    writeCensoredFile << censoredDocument;
    writeCensoredFile.close();


}