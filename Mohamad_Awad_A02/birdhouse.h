#ifndef BIRDHOUSE_H
#define BIRDHOUSE_H

#include <string>

class birdhouse {
public:

    birdhouse(std::string fileName) {
        this -> fileName = fileName;
    };
    ~birdhouse();

    std::string userGuess;
    std::string fileName;

    std::string concatenator(std::string fileName);
    std::string fileOpenerANDwordGenerator();
    void playGame();

    // setters and getters
    void setWordList (std::string myWordlist) { *wordList = myWordlist;} //setter for wordList
    std::string getWordList() const { return *wordList; } //getter for wordList

    void setNumOfWords (unsigned short int numbOFwords) {NumWords = numbOFwords;} //setter for numOfWords
    unsigned short int getNumOfWords() const { return NumWords; } //getter for numOfWords

    void setrandomWord (std::string randWord) { randomWord = randWord;} //setter for randomWord
    std::string getrandomWord() const { return randomWord; } //getter for randomWord

    void setWordLength (unsigned short int wrdLength) {wordLength = wrdLength;} //setter for numOfWords
    unsigned short int getWordLength() const { return wordLength; } //getter for numOfWords

    void setUInput (unsigned short int usrINPUT) {uInput = usrINPUT;} //setter for uInput
    unsigned short int getUInput() const { return uInput; } //getter for uInput

private:
    std::string* wordList;
    std::string randomWord;
    unsigned short int NumWords;
    unsigned short int numGuess;
    char uInput;
    unsigned short int wordLength;
};

#endif // BIRDHOUSE_H