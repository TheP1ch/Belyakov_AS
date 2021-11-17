//
// Created by Евгений Беляков on 15.11.2021.
//

#include "CS.h"
#include <iostream>
#include "verification.h"
#include "consolef.h"

void Clear_console();

int CS::Max_ID = 0;

CS::CS(){
    id = ++Max_ID;
    std::cout <<"Enter the name of cs, which have length in range (1 - 10):  ";
    verification::check_string(name, 10);
    Console_func::Clear_console();
    std::cout << "Enter the count of workshops in range (1 - 20): ";
    verification::add_attributes(count_workshops, 1, 20);
    Console_func::Clear_console();
    std::cout << "Enter the count of ready's workshops in range (0 - n) (n - is how many workshops you have): ";
    verification::add_attributes(count_ready_workshops, 0, count_workshops);
    Console_func::Clear_console();
    std::cout << "Enter the efficiency in range (0 - 100%): ";
    verification::add_attributes(efficiency, 0, 100);
    Console_func::Clear_console();
}


int CS::get_id() const{
    return id;
}

void CS::change_workshops(){
    std::cout << "Your CS had " << count_ready_workshops << " ready workshops" << std::endl;
    std::cout << "Enter the count of ready's workshops in range (0 - n) (n - is how many workshops you have):";
    verification::add_attributes(count_ready_workshops, 0, count_workshops);
}

std::ostream& operator << (std::ostream& out, const CS &cs){
    out << std::endl << "CS id: " << cs.get_id() << std::endl << "CS name: " << cs.name << std::endl
         << "CS count workshops: " << cs.count_workshops
         << std::endl << "CS count ready workshops: " << cs.count_ready_workshops<< std::endl << cs.efficiency;
    return out;
}

std::ofstream& operator << (std::ofstream& f_out, const CS &cs){
    f_out << cs.get_id() << std::endl << cs.name << std::endl << cs.count_workshops
        << std::endl << cs.count_ready_workshops << std::endl
        << cs.efficiency << std::endl;
    return f_out;
}

std::ifstream& operator >> (std::ifstream& f_in, CS &cs){
    while (f_in.peek() != -1) {
        getline(f_in, cs.name);
        f_in >> cs.count_workshops;
        f_in >> cs.count_ready_workshops;
        f_in >> cs.efficiency;
        f_in.ignore(1000, '\n');
    }
    return f_in;
}
