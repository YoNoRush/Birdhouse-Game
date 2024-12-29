#include "birdhouse.h"
#include <iostream>


int main () {

    std::string myFile;
    std::cout << "Welcome to Birdhouse, please input the file name: " << std::endl;
    getline(std::cin, myFile);

    birdhouse myBirdhouse(myFile);

    myBirdhouse.concatenator(myFile);
    myBirdhouse.fileOpenerANDwordGenerator();
    myBirdhouse.playGame();

    std::cout << "Thanks for playing! Press re-run to play again!" << std::endl;

    return 0;
}

