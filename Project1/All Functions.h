#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

/* Essential Functions */
int wordCounter(std::string fileName);
void readText(std::string& document, std::string fileName);
void tokenizeText(std::vector<std::string>& document, std::string fileName);
void cloningDocument(std::string duplicateFile, std::string originalFile);
void censoringData(std::string censoredDocument, std::vector<std::string> uncompletedDocument);

/* KMP Functions */
void computeLPSArray(std::string pat, int M, std::vector<int> lps);
int KMPSearch(std::string pat, std::string txt, int startingPoint);
