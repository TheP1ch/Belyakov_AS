//
// Created by Евгений Беляков on 17.11.2021.
//
#include "consolef.h"

void Console_func::Menu_out() {
    std::cout << "1. Добавить трубу\n"
            "2. Добавить КС\n"
            "3. Просмотр всех объектов\n"
            "4. Редактировать трубу\n"
            "5. Редактировать КС\n"
            "6. Сохранить\n"
            "7. Загрузить\n"
            "0. Выход\n";
}

void Console_func::Clear_console(){
    std::cout << std::string(20, '\n');
}

void Console_func::return_to_menu(){
    std::cout << "for return to menu push '1' button ";
    std::cin >> std::ws;
    while (true) {
        if (std::cin.get() == '1') {
            break;
        }else{
            Clear_console();
            std::cout << "for return to menu push '1' button, you push wrong button ";
        }
    }
}
