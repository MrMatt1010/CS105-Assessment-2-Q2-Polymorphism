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
//Here is the constructor for the computer system.
};

int main()
{
    std::cout << "Hello World!\n";
}

