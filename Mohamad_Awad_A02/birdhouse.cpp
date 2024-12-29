#include "birdhouse.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <algorithm>
using namespace std;

std::string birdhouse::concatenator(std::string fileName) {
    std::string extension = ".txt";
    std::string wholeFileName = fileName + extension;
    return wholeFileName;
};

std::string birdhouse::fileOpenerANDwordGenerator() {

    std::string wholeFileName = concatenator(fileName);
    std::ifstream file1;

    file1.open(wholeFileName);

    std::string line;

    if(!file1.is_open()) {
        cout << "Error opening file";
    }

    else {
        std::string myTextArray[100];
        NumWords = 0;
        while(file1.good()) {

            while (!file1.eof()) {

                file1 >> myTextArray[NumWords];
                NumWords++;
            }

            wordList = new string[NumWords];

            copy(myTextArray, myTextArray+NumWords, wordList);

            srand(time(0));
            int RandIndex = rand() % (NumWords+1);
            randomWord = wordList[RandIndex];
            return randomWord;
        }
    };
}

void birdhouse::playGame() {
    wordLength = randomWord.length();
    cout << endl << "Word Length: " << wordLength << endl;
    char randWordArray[wordLength];

    std::strcpy(randWordArray, randomWord.c_str());

    for (int i = 0; i<wordLength;i++) {
        randWordArray[i] = '_';
    }

    int game = 1;
    numGuess;


    while (game == 1) {

        int guessWord;

        cout << "Would you like to guess the word or guess a letter? (0 for word // 1 for letter): " << endl;
        cin >> guessWord;

        if (guessWord == 1) {
            cout << randWordArray << endl;
            cout << "Enter a character: ";
            cin >> uInput;

            bool found = false;
            for (int i = 0; i < wordLength; i++) {
                if (randomWord[i] == uInput) {
                    randWordArray[i] = uInput;
                    found = true;
                }
            }

            cout << randWordArray << endl;

            if (!found) {
                numGuess++;
                switch(numGuess) {
                    case 1:
                        cout << "Wrong! You got 7 chances left!" << endl;
                        cout << "------------ \n "
                                "|            | \n"
                                "|           \n"
                                "| \n"
                                "| \n"
                                "| \n"
                                "| \n"
                                "| \n |" << endl;
                        break;
                    case 2:
                        cout << "Wrong! You got 6 chances left!" << endl;
                        cout << "------------ \n "
                                "|            | \n"
                                "|             \\ \n"
                                "|              \\ \n"
                                "|               \\ \n"
                                "| \n"
                                "| \n"
                                "| \n |" << endl;
                        break;
                    case 3:
                        cout << "Wrong! You got 5 chances left!" << endl;
                        cout << "------------ \n "
                                "|            | \n"
                                "|          // \\ \n"
                                "|         //   \\ \n"
                                "|        //     \\ \n"
                                "| \n"
                                "| \n"
                                "| \n |" << endl;
                        break;
                    case 4:
                        cout << "Wrong! You got 4 chances left!" << endl;
                        cout << "------------ \n "
                                "|            | \n"
                                "|          // \\ \n"
                                "|         //   \\ \n"
                                "|        //     \\ \n"
                                "|        - - - - - \n"
                                "| \n"
                                "| \n |" << endl;
                        break;
                    case 5:
                        cout << "Wrong! You got 3 chances left!" << endl;
                        cout << "------------ \n "
                                "|            | \n"
                                "|          // \\ \n"
                                "|         //   \\ \n"
                                "|        //     \\ \n"
                                "|        - - - - - \n"
                                "|       {\n"
                                "|       {\n |" << endl;
                        break;
                    case 6:
                        cout << "Wrong! You got 2 chances left!" << endl;
                        cout << "------------ \n "
                                "|            | \n"
                                "|          // \\ \n"
                                "|         //   \\ \n"
                                "|        //     \\ \n"
                                "|        - - - - - \n"
                                "|       {         }\n"
                                "|       {         }\n |" << endl;
                        break;
                    case 7:
                        cout << "Wrong! You got 1 chance left!!!" << endl;
                        cout << "------------ \n "
                                "|            | \n"
                                "|          // \\ \n"
                                "|         //   \\ \n"
                                "|        //     \\ \n"
                                "|        - - - - - \n"
                                "|       {         }\n"
                                "|       {_________}\n |" << endl;
                        break;
                    case 8:
                        cout << "GAME OVER! The word was " << randomWord << "!" << endl;
                        cout << "------------ \n "
                                "|            | \n"
                                "|          // \\ \n"
                                "|         //   \\ \n"
                                "|        //     \\ \n"
                                "|        - - - - - \n"
                                "|       {         }\n"
                                "|       {____0____}\n |" << endl;
                        game = 0;
                        break;
                    default:
                        std::cout << "EASTER EGG!" << endl;
                        break;
                }
            }
        }

        else {
            std::string myWord;
            cout << "Guess the word! : ";
            cin>>myWord;

            if (myWord == randomWord) {
                cout << "CONGRATS! YOU GUESSED THE WORD!!!" << endl;
                game = 0;
            }
            else {
                cout << "Sorry, wrong word! GAME OVER!" << endl;
                game = 0;
            }
        }
    }
}

birdhouse::~birdhouse() {
    if (wordList) {
        delete[] wordList;
    }
}