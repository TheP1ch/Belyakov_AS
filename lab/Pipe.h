//
// Created by Евгений Беляков on 15.11.2021.
//

#ifndef LAB_PIPE_H
#define LAB_PIPE_H
#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>


class Pipe{
private:
    int id;
public:
    static int Max_ID;
    double length;
    std::string name;
    int  diameter;
    bool repair_or_not;
    int get_id() const;
    static void PIPE_Clear(std::unordered_map<int, Pipe> &pipes);
    void Add_pipe_attribute();
    friend std::ostream& operator << (std::ostream& out, const Pipe &pipe);
    friend std::ofstream& operator << (std::ofstream& f_out, const Pipe &pipe);
    friend std::ifstream& operator >> (std::ifstream& f_in, Pipe &pipe);
};



#endif //LAB_PIPE_H
