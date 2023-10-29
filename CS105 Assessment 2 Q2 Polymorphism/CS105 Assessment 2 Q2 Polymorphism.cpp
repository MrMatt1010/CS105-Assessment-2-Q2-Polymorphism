// CS105 Assessment 2 Q2 Polymorphism
// Student Name: Matt Taylor
//This program allows the store manager to input computer and console games with prices to an array


#include <iostream>
#include <iomanip>
#include <string>
#define MAX_SIZE 120


//vidoeGame Base class
class videoGame {
protected:
    std::string title;
    float price;

public:
    videoGame() : title(""), price(0) {};
    videoGame(std::string t, float p) : title(t), price(p) {};
    
    virtual void display() {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Price: " << std::fixed << std::setprecision(2) << price << std::endl;
        displayDetails(); // Call the virtual displayDetails() method
    }

    virtual void displayDetails() {} // Virtual method for displaying details
};

//computerGame  child class 
class computerGame : public videoGame {
private:
    std::string operatingSystem;

public:
    computerGame(std::string t, float p, std::string o) : videoGame(t, p), operatingSystem(o) {}

    void displayDetails() override {
        std::cout << "OS Type: " << operatingSystem << std::endl;
    }
};

//consoleGame child class
class consoleGame : public videoGame {
private:
    std::string consoleType;

public:
    consoleGame(std::string t, float p, std::string c) : videoGame(t, p), consoleType(c) {}

    void displayDetails() override {
        std::cout << "Console Type: " << consoleType << std::endl;
    }
};

//Displays list of computer games after the user has entered all they want to
void displayVideoGames(videoGame** videoGamesList, int size) {
    std::cout << "Video Games List" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << "*********************************" << std::endl;
        videoGamesList[i]->display();
        std::cout << "\n*******************************" << std::endl;
    }
}

int main() {
    videoGame* videoGames[MAX_SIZE];
    int currentSize = 0;

    char userChoice;
//Do while loop that allows the user to input games, prices as well as OS and Console type
    do {
        char videoGameType;
        std::string gameTitle;
        float price;

        std::cout << "Do you want to enter data for a Computer Game or a Console Game (o / c) : ";
        std::cin >> videoGameType;
        if (videoGameType == 'c') {
            std::string consoleType;
            std::cout << "Please enter the title of console game: ";
            std::cin.ignore();
            std::getline(std::cin, gameTitle);
            std::cout << "Please enter the price: ";
            std::cin >> price;
            std::cout << "Please enter console type: ";
            std::cin.ignore();
            std::getline(std::cin, consoleType);
            consoleGame* newConsoleGame = new consoleGame(gameTitle, price, consoleType);
            videoGames[currentSize++] = newConsoleGame;
        }
        else if (videoGameType == 'o') {
            std::string osType;
            std::cout << "Please enter the title of the computer game: ";
            std::cin.ignore();
            std::getline(std::cin, gameTitle);
            std::cout << "Please enter the price: ";
            std::cin >> price;
            std::cin.ignore();
            std::cout << "Please enter the operating system (OS): " << std::endl;
            std::getline(std::cin, osType);
            computerGame* newComputerGame = new computerGame(gameTitle, price, osType);
            videoGames[currentSize++] = newComputerGame;
        }
        else {
            std::cout << "Please enter a valid choice";
        }

        std::cout << "Do you want to add another game?: ";
        std::cin >> userChoice;
    } while (userChoice == 'y' || userChoice == 'Y');

    std::cout << std::endl;
    displayVideoGames(videoGames, currentSize);

    for (int i = 0; i < currentSize; i++) {
        delete videoGames[i]; //Frees up memory once it's not needed
    }
}

