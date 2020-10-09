// SFTM_Hangman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string.h>


using namespace std;


void textToLowerCase() {//only used once, to replace the file and weed out non-word words
    ifstream textFile("words.txt");
    ofstream textFileOut("wordsLower.txt");
    string line = "";
    string outLine = "";
    int numLines = 0;
    if (textFile) {
        //check first word
        while (getline(textFile, line)) {//loop through each line
            outLine = "";
            for (unsigned int i = 0; i < line.length(); i++) {
                //make each word lowercase
                outLine += (char)std::tolower(line[i]);
            }
            if (outLine != "") {//if the output line is not empty
                textFileOut << outLine << '\n';
            }
            numLines++;
        }
        //remove repeats
        textFile.close();
        textFileOut.close();
        textFile.open("wordsLower.txt");
        while (getline(textFile, line)) {

        }
    }
    textFile.close();
}



int main()
{
    //textToLowerCase(); //only call once

    //add +1 length for null-terminated string
    char word0[6] = "_____";
    char word1[2] = "_";
    char word2[8] = "_______";
    //a in word 1 slot 0
    //b in word 2 slot 3

    ifstream textFile("wordsLower.txt");
    string line;
    int firstCount = 0;
    int secondCount = 0;
    int thirdCount = 0;
    if (textFile) {
        //check first word
        while (getline(textFile, line)) {
            if (line.length() == strlen(word0)) {
                cout << line << "\n";
                firstCount++;
            }

        }
    }
    textFile.close();

    textFile.clear();
    textFile.open("wordsLower.txt");
    if (textFile) {
        //check second word
        while (getline(textFile, line)) {
            if (line.length() == strlen(word1)) {
                if (line.at(0) == 'a') {
                    cout << "\t" << line << "\n";
                    secondCount++;
                }
            }

        }
    }
    textFile.close();


    textFile.clear();
    textFile.open("wordsLower.txt");
    if (textFile) {
        //check second word
        while (getline(textFile, line)) {
            if (line.length() == strlen(word2)) {
                if (line.at(3) == 'b') {
                    cout << "\t\t" << line << "\n";
                    thirdCount++;
                }
            }

        }
    }
    textFile.close();
    std::cout << "first: " << firstCount << "   second: " << secondCount << "   third: " << thirdCount;
}

