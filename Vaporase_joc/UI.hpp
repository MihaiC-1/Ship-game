//
//  UI.hpp
//  Vaporase_joc
//
//  Created by Comsa Mihai on 04/06/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#include <stdio.h>
#pragma once
#include "Service.hpp"

using namespace std;

class UI
{
private:
    Service serv_user;
    Service serv_computer;
    bool user_turn;
    
    void put_user_ships();
    void put_computer_ships();
    void make_user_move();
    void print_table(bool turn);
public:
    UI();
    UI(Service serv_user, Service serv_computer);
    ~UI();
    void start_game();
};
