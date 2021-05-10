//
//  UI.cpp
//  Vaporase_joc
//
//  Created by Comsa Mihai on 04/06/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#include "UI.hpp"
#include <stdio.h>
#include <iostream>
#include <sstream>
#include "RepoException.hpp"

using namespace std;

void UI::print_table(bool turn)
{
    int u;
    if (turn == false)
    {
        cout << " User Table : \n";
        u = this->serv_user.get_table_dim();
    }
    else
    {
        cout << " Computer Table : \n";
        u = this->serv_computer.get_table_dim();
    }
    cout << "============================================\n";
    
    for (int i = 0; i < u; i++)
    {
        for (int j = 0; j < u; j++)
        {
            CellState var;
            if (turn == false)
                var = this->serv_user.get(i, j);
            else
                var = this->serv_computer.get(i, j);
            switch (var)
            {
                case CellState::Water :
                    cout << " _ ";
                    break;
                case CellState::Ship :
                    if (turn == false)
                        cout << " W ";
                    else
                        cout << " _ ";
                    break;
                case CellState::Hit :
                    cout << " X ";
                    break;
                case CellState::Missed :
                    cout << " O ";
                    break;
                default:
                    break;
            }
        }
        cout << "\n";
    }
}

void UI::put_user_ships()
{
    int type_ship = 1;
    
    while (type_ship <= 6)
    {
        this->print_table(false);
        int x = -1, y = -1;
        string orie;
        bool cell_free;
        bool is_ok;
        do
        {
            cell_free = true;
            is_ok = true;
            
            try
            {
                cout << "Scrieti pozitia unde se va afla nava si orintarea ei. \n";
                cout << "EXEMPLU < Linie : C, Coloana : 4, Orintare : 1 (orizontal) / 2 (vertical) > \n";
                cout << " Linie : ";
                char op;
                cin >> op;
                x = (int) op - 65;
                cout << " Coloana : ";
                string a;
                cin >> a;
                y = stoi(a);
                y = y - 1;
                cout << " Orintarea : ";
                cin >> orie;
                if (orie == "1")
                {
                    int j = y;
                    int aux;
                    if (type_ship <= 2)
                        aux = y + 4;
                    else if (type_ship <= 4)
                        aux = y + 2;
                    else
                        aux = y + 1;
                    while (j <= aux && cell_free == true)
                    {
                        cell_free = this->serv_user.check_cell_free(x, j);
                        j++;
                    }
                }
                else if (orie == "2")
                {
                    int i = x;
                    int aux;
                    if (type_ship <= 2)
                        aux = x + 4;
                    else if (type_ship <= 4)
                        aux = x + 2;
                    else
                        aux = x + 1;
                    while (i <= aux && cell_free == true)
                    {
                        cell_free = this->serv_user.check_cell_free(i, y);
                        i++;
                    }
                }
            }
            catch (RepoException& e)
            {
                cell_free = false;
                cout << e.what();
                cout << "Mai incercati ! \n";
            }
            catch (const exception&)
            {
                is_ok = false;
                cout << "Date invalide! Mai incercati: \n";
            }
        } while (!cell_free || !is_ok);
        try
        {
            if (orie == "1")
            {
                int j = y;
                int aux;
                if (type_ship <= 2)
                    aux = y + 4;
                else if (type_ship <= 4)
                    aux = y + 2;
                else
                    aux = y + 1;
                while (j <= aux)
                {
                    this->serv_user.make_move(x, j, CellState::Ship);
                    j++;
                }
            }
            else if (orie == "2")
            {
                int i = x;
                int aux;
                if (type_ship <= 2)
                    aux = x + 4;
                else if (type_ship <= 4)
                    aux = x + 2;
                else
                    aux = x + 1;
                while (i <= aux)
                {
                    this->serv_user.make_move(i, y, CellState::Ship);
                    i++;
                }
            }
            else
                cout << "Nu exista aceasta orientare ! \n";
        }
        catch (exception e)
        {
            cout << e.what();
        }
        type_ship += 1;
        if (type_ship == 7)
            this->print_table(false);
    }
}

void UI::put_computer_ships()
{
    int type_ship = 1;
    
    while (type_ship <= 6)
    {
        int x = -1, y = -1;
        int orie = 1;
        bool cell_free = false;
        while (cell_free == false)
        {
            try
            {
                x = rand() % 10;
                y = rand() % 10;
                orie = rand() % 2 + 1;
                bool ok = true;
                if (orie == 1)
                {
                    int j = y;
                    int aux;
                    if (type_ship <= 2)
                        aux = y + 4;
                    else if (type_ship <= 4)
                        aux = y + 2;
                    else
                        aux = y + 1;
                    while (j <= aux && ok == true)
                    {
                        ok = this->serv_computer.check_cell_free(x, j);
                        j++;
                    }
                }
                else if (orie == 2)
                {
                    int i = x;
                    int aux;
                    if (type_ship <= 2)
                        aux = x + 4;
                    else if (type_ship <= 4)
                        aux = x + 2;
                    else
                        aux = x + 1;
                    while (i <= aux && ok == true)
                    {
                        ok = this->serv_computer.check_cell_free(i, y);
                        i++;
                    }
                }
                cell_free = ok;
            }
            catch (RepoException& e)
             {
                cell_free = false;
            }
        }
        try
        {
            if (orie == 1)
            {
                int j = y;
                int aux;
                if (type_ship <= 2)
                    aux = y + 4;
                else if (type_ship <= 4)
                    aux = y + 2;
                else
                    aux = y + 1;
                while (j <= aux)
                {
                    this->serv_computer.make_move(x, j, CellState::Ship);
                    j++;
                }
            }
            else if (orie == 2)
            {
                int i = x;
                int aux;
                if (type_ship <= 2)
                    aux = x + 4;
                else if (type_ship <= 4)
                    aux = x + 2;
                else
                    aux = x + 1;
                while (i <= aux)
                {
                    this->serv_computer.make_move(i, y, CellState::Ship);
                    i++;
                }
            }
        }
        catch (exception e)
        {
            cout << e.what();
        }
        type_ship += 1;
    }
}

void UI::make_user_move()
{
    int x = -1, y = -1;
    bool cell_fire = false;

    while (cell_fire != true)
    {
        try
        {
            cout << " Linie : ";
            char op;
            cin >> op;
            x = (int) op - 65;
            cout << " Coloana : ";
            string a;
            cin >> a;
            y = stoi(a);
            y = y - 1;
            bool ok = this->serv_computer.check_cell_free_for_fire(x, y);
            cell_fire = ok;
        }
        catch (RepoException& e)
        {
            cell_fire = false;
            cout << e.what();
            cout << " Mai incearca : ";
        }
        catch (const exception&)
        {
            cell_fire = false;
            cout << "Date invalide! Mai incercati: \n";
        }
    }
    this->serv_computer.make_move(x, y, CellState::Hit);
}

UI::UI()
{
}

UI::UI(Service serv_user, Service serv_computer)
{
    this->serv_user = serv_user;
    this->serv_computer = serv_computer;
}

UI::~UI()
{
}

void UI::start_game()
{
    Here:
    this->user_turn = true;
    this->serv_user.init_data();
    this->serv_computer.init_data();
    this->put_computer_ships();
    this->put_user_ships();
    
    bool is_winner = false;
    
    do
    {
        if (this->user_turn == true)
        {
            this->print_table(this->user_turn);
            this->make_user_move();
            is_winner = this->serv_computer.check_winner();
        }
        else
        {
            this->serv_user.random_move();
            this->print_table(this->user_turn);
            is_winner = this->serv_user.check_winner();
        }
        
        this->user_turn = !this->user_turn;
    } while ( is_winner != true);
    if (this->user_turn == false)
    {
        cout << "Felicitari! Ai castigat !";
    }
    else
    {
        cout << "Computer-ul a castigat !";
    }
    string remach;
    cout << " Vrei sa joci din nou? \n";
    cin >> remach;
    if (remach == "DA" || remach == "da")
    {
        goto Here;
    }
}
