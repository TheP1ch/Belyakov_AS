//
// Created by Евгений Беляков on 15.11.2021.
//

#ifndef LAB_CS_H
#define LAB_CS_H
#pragma once
#include <iostream>
#include <fstream>
#include <string>

class CS {
private:
    int id;
public:
    static int Max_ID;
    std::string name;
    int count_workshops;
    int count_ready_workshops;
    double efficiency;
    CS();
    int get_id() const;
    void change_workshops();
    friend std::ostream& operator << (std::ostream& out, const CS &cs);
    friend std::ofstream& operator << (std::ofstream& f_out, const CS &cs);
};


#endif //LAB_CS_H
