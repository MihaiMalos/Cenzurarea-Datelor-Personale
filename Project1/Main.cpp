#include "All Functions.h"


int main()
{
    int n;
    std::cout << "Choose a document from 1 to 3: "; 
    do
    {
        std::cin >> n;
        if (n < 1 || n > 3) std::cout << "You have to choose a number from 1 to 3: ";
    } while (n < 1 || n > 3);
    std::vector<std::string> uncompletedDocument;
    std::string censoredDocument;
    tokenizeText(uncompletedDocument, std::string("./text_files/input/") + std::to_string(n) + std::string("_Uncompleted Document.txt"));
    cloningDocument("./text_files/output/Censored Document.txt", std::string("./text_files/input/") + std::to_string(n) + std::string("_Original Document.txt"));
    readText(censoredDocument, "./text_files/output/Censored Document.txt");
    censoringData(censoredDocument, uncompletedDocument);
    std::cout << "The document has been censored succesfully! You can find it in the output section of the project\n\n";
    

    return 0;
}