//
// Created by Евгений Беляков on 15.11.2021.
//

#include "CS.h"
#include <iostream>
#include "verification.h"

void Clear_console();

int CS::Max_ID = 0;

CS::CS(){
    id = ++Max_ID;
    std::cout <<"Enter the name of cs, which have length in range (1 - 10):  ";
    verification::check_string(name, 10);
    Clear_console();
    std::cout << "Enter the count of workshops in range (1 - 20): ";
    verification::add_attributes(count_workshops, 1, 20);
    Clear_console();
    std::cout << "Enter the count of ready's workshops in range (0 - n) (n - is how many workshops you have): ";
    verification::add_attributes(count_ready_workshops, 0, count_workshops);
    Clear_console();
    std::cout << "Enter the efficiency in range (0 - 100%): ";
    verification::add_attributes(efficiency, 0, 100);
    Clear_console();
}


int CS::get_id() const{
    return id;
}

void CS::change_workshops(){
    std::cout << "Your CS had " << count_ready_workshops << " ready workshops" << std::endl;
    std::cout << "Enter the count of ready's workshops in range (0 - n) (n - is how many workshops you have):";
    verification::add_attributes(count_ready_workshops, 0, count_workshops);
}