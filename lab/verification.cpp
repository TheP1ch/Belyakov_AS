//
// Created by Евгений Беляков on 15.11.2021.
//

#include "verification.h"


bool verification::check_int_double(){
    if (std::cin.peek() != '\n' || !std::cin){
        std::cout << "YOUR NUMBER IS WRONG" << std::endl;
        std::cin.clear();
        std::cin.ignore(15000, '\n');
        std::cout << "Enter a new number: ";
        return false;
    }else{
        return true;
    }
}

void verification::check_string(std::string &string_cin, int max_symbols) {
    while (true) {
        getline(std::cin >> std::ws, string_cin);
        string_cin.erase(string_cin.find_last_not_of(' ') + 1);
        if (!string_cin.empty() && string_cin.size() <= max_symbols) {
            break;
        }
    }
}

void verification::true_false(bool &repair){
    char true_false;
    while(true){
        std::cin >> std::ws;
        true_false = char(std::cin.get());
        std::cin.ignore(10000, '\n');
        if (true_false == 'y'){
            repair = true;
            break;
        } else if (true_false == 'n'){
            repair = false;
            break;
        }else
            std::cout << "You push the wrong button, please try again: ";
    }
}
