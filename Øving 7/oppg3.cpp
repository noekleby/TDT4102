//
//  oppg3.cpp
//  Øving 7
//
//  Created by Magnus Pedersen on 06.03.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#include "oppg3.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
void ordstatistikk()
{
    vector<int> wordOccurences;
    vector<string> word;
    
    int wordcount = 0;
    int totlines = 0;
    string longestWord = "";

    ifstream in("oppg1a.txt");
    if (!in) //samme som in.good()
    {
        cout << "Cannot open file.\n";
        exit(1);
    }
    string lines;
    while (getline(in, lines))//"the macho way"
    {
        totlines++;
        stringstream ss;
        ss << lines;
        string buffer;
        buffer = onlyAlphaCharacters(buffer);
        while (ss >> buffer)
        {
            bool containsWord = false;
            for (int i = 0; i < word.size(); i++)
            {
                if (onlyAlphaCharacters(buffer).compare(word[i]) == 0)
                {
                    containsWord = true;
                    wordOccurences[i]++;
                    break;
                }
            }
            if (!containsWord)
            {
                if (onlyAlphaCharacters(buffer).size() > longestWord.size())
                {
                    longestWord = onlyAlphaCharacters(buffer);
                }
                word.push_back(onlyAlphaCharacters(buffer));
                if (onlyAlphaCharacters(buffer)!="")
                {
                    wordcount++;
                    wordOccurences.push_back(1);
                }
            }
        }
    }
    cout << "Text statistics:" << endl << "----------------------------" << endl;
    cout << "Number of words: " << wordcount << endl;
    cout << "Number of lines: " << totlines << endl;
    cout << "Longest word: " << longestWord << endl;
    for (int i = 0; i < word.size(); i++)
    {
        if (onlyAlphaCharacters(word[i])!="")
        {
            cout << word[i] << ":  " << wordOccurences[i] << endl;
        }
    }
    in.close();
}
string onlyAlphaCharacters(string s)
{
    string clearedString = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (isalpha(s[i]))
        {
            char c = tolower(s[i]);
            clearedString += c;
        }
    }
    return clearedString;
}