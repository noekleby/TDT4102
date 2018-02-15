//
//  Substitution.h
//  Øving 7
//
//  Created by Magnus Pedersen on 06.03.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#ifndef ___ving_7__Substitution__
#define ___ving_7__Substitution__

#include <iostream>
#include <map>
class Substitution
{
public:
    Substitution(char filename[]);
    void play();
private:
    const int maxLength = 40;
    std::map<char,char> cipher;
    std::map<char,char> decodeCipher;
    std::map<char,char> guessCipher;
    std::string ciphertext;
    std::string rawText;
    std::string plaintext;
    char encodeChar(char a, std::map<char,char>&);
    std::string encodeString(std::string plainText, std::map<char,char>&);
    int countSpaces(std::string input);
    int checkForErrors(std::string input);
    std::string cleanString(std::string input);
    void generateCipher();
    void selectRandomText();
    void askUser();
    int printErrors(std::string userPlaintext);
    void printUserInformation(std::string userPlaintext);
    std::string parseDecryptedText(std::string userPlaintext);
};
#endif /* defined(___ving_7__Substitution__) */
