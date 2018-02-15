//
//  Substitution.cpp
//  Øving 7
//
//  Created by Magnus Pedersen on 06.03.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#include "Substitution.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>
using namespace std;
string Substitution::cleanString(string input)
{
    string clearedString = "";
    for (int i = 0; i < input.size(); i++)
    {
        if (isalpha(input[i]))
        {
            char c = tolower(input[i]);
            clearedString += c;
        }
    }
    return clearedString;
}
Substitution::Substitution(char filename[])
{
	ifstream file(filename);
    if (!file)
    {
        cout << "Error" << endl;
    }
	char ch;
	while (file.get(ch))
    {
		ch = tolower(ch);
		if (isalpha(ch))
        {
			rawText.append(&ch);
        }
		else if ((isblank(ch)) || strcmp(&ch, "\n"))
        {
			rawText.append(" ");
        }
	}
}
void Substitution::selectRandomText()
{
    stringstream sstream;
    sstream << rawText;
    int randomStart = rand() % rawText.length() - maxLength;
    int charcount = 0;
    string word;
    string returnstring = " ";
    while (sstream >> word)
    {
        charcount += (word.length() + 1);
        if (charcount > randomStart && charcount < (randomStart + maxLength))
        {
            returnstring.append(word + ' ');
        }
    }
    plaintext = returnstring;
}
void Substitution::generateCipher()
{
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
	string shuffle = alphabet;
	string guess = alphabet;
	random_shuffle(shuffle.begin(), shuffle.end()); //shuffler alfabetet
	random_shuffle(guess.begin(), guess.end());
    for (int i = 0; i < 26; i++)
    {
		cipher[alphabet[i]] = shuffle[i];
		decodeCipher[shuffle[i]] = alphabet[i];
		guessCipher[alphabet[i]] = guess[i];
	}
	ciphertext = "";
	for (int i = 0; i < plaintext.size(); i++)//Lager ciphertekst
    {
		if (guessCipher.find(plaintext[i]) == guessCipher.end())//Sjekker om det ikke er en bokstav
        {
			ciphertext += plaintext[i]; //Hvis det ikke er bokstav
		}
		else
        {
			ciphertext += guessCipher[plaintext[i]];
		}
	}
}
char Substitution::encodeChar(char a, map<char, char>& m)
{
	if (isalpha(m[a])) //Konverteres til en kodet bokstav med map hvis det er en bokstav
    {
        return m[a];
    }
	else
    {
		return a;
    }
}
string Substitution::encodeString(string plainText, map<char, char>& m)
{
	string codedString = "";
	for (int i = 0; i < plainText.size(); i++)
    {
		codedString += encodeChar(plainText[i], m);
	}
	return codedString;
}
int Substitution::countSpaces(string input)
{
	unsigned int antallSpaces = 0;
	for (int i = 0; i < input.size(); i++)
    {
		if (isblank(input[i]))
        {
			antallSpaces++;
        }
	}
	return antallSpaces;
}
int Substitution::checkForErrors(string input)
{
	string guess = cleanString(input);
	string answer = cleanString(plaintext);
	int errors = 0;
	for (int i = 0; i < answer.size(); i++)
    {
		if (guess[i] != answer[i])//sammenligner om plain og input er forskjellige
        {
			errors++;
        }
	}
	return errors;
}
void Substitution::askUser()
{
	char ny,gammel;
	cout << "Hvilken bokstav vil du endre? " << endl;
	cin >> gammel;
	cout << "Hva vil du substituere " << gammel << " med?" << endl;
	cin >> ny;
	if (isalpha(gammel))
    {
		guessCipher[gammel] = ny;
    }
}
int Substitution::printErrors(string userPlaintext)
{
	int errors = checkForErrors(userPlaintext);
    string clean = cleanString(userPlaintext);
	double percentage = (clean.size() - errors) * 100 / clean.size(); //prosent korrekte
    
	cout << "Antall feil: " << errors << " | Prosent riktige: " << percentage << " %" << endl;;
    
	return errors;
}
string Substitution::parseDecryptedText(string userPlaintext)
{
	string correctionCheck;
	for (int i = 0; i < plaintext.size(); i++)
    {
		if (plaintext[i] == userPlaintext[i])//Hvis riktig bokstav på riktig plass
        {
			correctionCheck += toupper(plaintext[i]);
        }
		else
        {
			correctionCheck += ciphertext[i];//Hvis ikke legges bokstaven fra ciphertext tilbake på plass igjen
		}
	}
	return correctionCheck;
}
void Substitution::printUserInformation(string userPlaintext)
{
	cout << "Ciphertext: " << ciphertext << endl;//utskrift av ciphertexten
	cout << "Brukerens forsøk: " << parseDecryptedText(userPlaintext) << endl;//utskrift av brukerens forsøk
}
void Substitution::play()
{
    srand(static_cast<unsigned>(time(0)));
    string svar = "";
	bool again = true;
	while (again)
    {
		selectRandomText();
		generateCipher();
		string guess = encodeString(ciphertext, guessCipher);
		do
        {
			cout << plaintext << endl; //er fasiten
			printErrors(guess);
			cout << endl;
			printUserInformation(guess);
			cout << endl;
			askUser();
			guess = encodeString(ciphertext, guessCipher);
		}while (checkForErrors(guess) > 0);
		cout << ciphertext << endl << guess << endl << endl;
		cout << "Gratulerer, du løste koden!" << endl;
        cout << "Vil du spille en gang til? (ja/nei)" << endl;
        cin >> svar;
        if (svar == "nei")
        {
            again = false;
        }
	}
}
