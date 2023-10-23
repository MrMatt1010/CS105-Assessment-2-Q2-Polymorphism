// CS105 Assessment 2 Q2 Polymorphism
// Student Name: Matt Taylor


#include <iostream>
#include <iomanip>
#include <string>
#define MAX_SIZE 150

//Video Game base class

class videoGame {
protected:
    std::string title; // Stores the title of the game
    float price;       //Stores the price of the game

public:
// Default constructor and array building to store objects entered IE: games and prices

    videoGame() : title(""), price(0) {};
    videoGame(std::string t, float p) : title(t), price(0) {};

// Virtual display method which can be overidden by the dreived classes

    void display() {
        std::cout << fixed << setPrecision(2);
        std::cout << "Title: " << title << std::endl;
        std::cout << "Price: " << price << std::endl;
    }

};

// This is the computerGame Class

class computerGame : public videoGame
{
private:
    std::string operatingSystem;
public:
//Here is the constructor for the computer system, Function calling the display method of the parent class

    consoleGame(std::string t, float p, std::string c) : videoGame(t, p), consoleType(c) {};
    void display() {
        videoGame::display();
        std::cout << "Console Type: " << consoleType << std::endl;
    }
};

//This functin displays the list of computer games once it has been created

void displayVideoGames(videoGame* videoGamesList, int size) {
    std::cout << "Video Games List" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << "*********************************" << std::endl;
        videoGamesList[i].display(); //Display function is called
        std::cout << "\n*******************************" << std::endl;
    }
}
int main()
{
    videoGame* videoGames = new videoGame[MAX_SIZE];
    int currentSize = 0;

    char userChoice;

    do {
        char videoGameType;
        std::string gameTitle;
        float price;

        std::cout << "Do you want to enter data for a computer game or a console game (o / c): ";
        std::cin >> videoGameType;
        if (videoGameType == 'c') {
            std::string consoleType;
            std::cout << "Please enter the title of the console game: ";
            (std::cin >> ws, gameTitle);
            std::cout << "Please enter the price: ";
            std::cin >> price;
            std::cout << "Please enter the console type: ";
            (std::cin >> ws, consoleType);
            consoleGame newConsoleGame(gameTitle, price, consoleType);
            //Adding the console to the video game list
            videoGames[currentSize++] = newConsoleGame;
        }
        else if (videoGameType == 'o') {
            std::string osType;
            std::cout << "Please enter the title of the computer game: ";
            (std::cin >> ws, gameTitle);
            std::cout << "Please enter the price: ";
            std::cin >> price;
            std::cout << "Please enter the operating system (OS): " << std::endl;
            (std::cin >> ws, osType);
            computerGame newComputerGame(gameTitle, price, osType);
            videoGames[currentSize++] = newComputerGame;
        }
        else
        {
            std::cout << "Please enter a valid choice";
        }
    std::cout << "Do you want to add another game?: ";
    std::cin >> userChoice;
    } while (userChoice == 'y' || userChoice == 'y');

    std::cout << std::endl;
    displayVideoGames(videoGames, currentSize);
}

