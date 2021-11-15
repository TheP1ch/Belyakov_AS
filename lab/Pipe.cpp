//
// Created by Евгений Беляков on 15.11.2021.
//

#include "Pipe.h"
#include <iostream>
#include "verification.h"

void Clear_console();

int Pipe::Max_ID = 0;

Pipe::Pipe(){
        id = ++Max_ID;
        std::cout << "Enter the diameter in millimeters in the range{114 - 1420}: ";
        verification::add_attributes(diameter, 110, 1420);
        Clear_console();
        std::cout << "Enter the length in meters in the range{10 - 100}: ";
        verification::add_attributes(length, 10, 100);
        Clear_console();
        std::cout << "in Repair or not in repair? (Push 'y'(not in repair) or 'n'(in repair) button): ";
        verification::true_false(repair_or_not);
        Clear_console();
}

int Pipe::get_id() const{
    return id;
}

void Pipe::switch_repair() {
    std::cout << "Your pipe ";
    if (repair_or_not) {
        std::cout << "not in repair" << std::endl;
    } else {
        std::cout << "in repair" << std::endl;
    }
    std::cout << "Enter pipe repair or not (Push 'y'(not in repair) or 'n'(in repair) button): ";
    verification::true_false(repair_or_not);
}
