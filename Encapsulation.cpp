#include <iostream>

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        balance -= amount;
    }

    void withdrawAvailable(double amount) {
        if (balance > amount)
        {
            withdraw(amount);
            std::cout << "Withdrawal successful. New balance: $" << getBalance() << std::endl;
        }
        else
        {
            std::cout << "Insufficient funds for withdrawal." << std::endl;
        }
    }
};
class HeatingSystem {
public:
    void turnOn() {
        std::cout << "Heating system turned on." << std::endl;
    }

    void turnOff() {
        std::cout << "Heating system turned off." << std::endl;
    }
};

class Thermostat {
private:
    double currentTemperature;
    double targetTemperature;

public:
    Thermostat(double temperature, double target) : currentTemperature(temperature), targetTemperature(target) {}

    double getCurrentTemperature() const {
        return currentTemperature;
    }

    bool isTooCold() const {
        if (currentTemperature < targetTemperature)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    bool isAvailable;

public:
    Book(const std::string& title) : title(title), isAvailable(true) {}

    bool checkAvailability() const {
        return isAvailable;
    }

    void borrowBook() {
        if (checkAvailability())
        {
            isAvailable = false;
            std::cout << "Book borrowed successfully." << std::endl;
        }
        else {
            std::cout << "Book is not available for borrowing." << std::endl;
        }
    }

    void returnBook() {
        isAvailable = true;
    }
};

class Library {
public:
    void processBookBorrowing(Book& book) {
        // Violates Tell, Don't Ask
        book.borrowBook();        
    }
};

class Player {
private:
    int health;
    int ammo;

public:
    Player() : health(100), ammo(10) {}

    int getHealth() const {
        return health;
    }

    int getAmmo() const {
        return ammo;
    }

    void takeDamage(int damage) {
        health -= damage;
    }

    void useAmmo() {
        ammo--;
    }

    bool canRespond() {
        if (getHealth() > 0 && getAmmo() > 0) {
            return true;
        }
        else
        {
            return false;
        }
    }
};

class Game {
public:
    void enemyAttack(Player& player) {
        if (player.canRespond())
        {
            player.takeDamage(10);
            player.useAmmo();
            std::cout << "Player attacked and used ammo." << std::endl;
        }
        else
        {
            std::cout << "Player can't respond to attack." << std::endl;
        }
    }
};


int main() {
    //////////////////////////////////////////////////////////////////
    // Exercise 1
    //////////////////////////////////////////////////////////////////
 
    BankAccount account(1000.0);

    // Violation of Tell, Don't Ask
    /*if (account.getBalance() > 500) {
        account.withdraw(500);
        std::cout << "Withdrawal successful. New balance: $" << account.getBalance() << std::endl;
    }
    else {
        std::cout << "Insufficient funds for withdrawal." << std::endl;
    }*/

    account.withdrawAvailable(500);

    //////////////////////////////////////////////////////////////////
    // Exercise 2
    //////////////////////////////////////////////////////////////////

    Thermostat thermostat(18.5, 20.0);
    HeatingSystem heating;

    if (thermostat.isTooCold()) {
        heating.turnOn();
    }
    else {
        heating.turnOff();
    }
    
    //////////////////////////////////////////////////////////////////
    // Exercise 3
    //////////////////////////////////////////////////////////////////

    Book myBook("1984");
    Library library;

    library.processBookBorrowing(myBook);  // First borrow should succeed
    library.processBookBorrowing(myBook);  // Second attempt should show not available

    //////////////////////////////////////////////////////////////////
    // Exercise 4
    //////////////////////////////////////////////////////////////////
    Player player;
    Game game;

    game.enemyAttack(player); // Player can respond to attack

    return 0;
}
