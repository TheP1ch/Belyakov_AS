//
// Created by Евгений Беляков on 15.11.2021.
//

#ifndef LAB_PIPE_H
#define LAB_PIPE_H
#pragma once
#include <string>
#include <iostream>


class Pipe{
private:
    int id;
public:
    static int Max_ID;
    double length;
    std::string name;
    int  diameter;
    bool repair_or_not;
    Pipe();
    void switch_repair();
    int get_id() const;
    friend std::ostream operator << ();
};



#endif //LAB_PIPE_H
