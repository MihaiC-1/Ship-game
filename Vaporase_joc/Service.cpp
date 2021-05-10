//
//  Service.cpp
//  Vaporase_joc
//
//  Created by Comsa Mihai on 03/06/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#include "Service.hpp"
#include "RepoException.hpp"

Service::Service()
{
    
}

Service::Service(Repo repo)
{
    this->repo = repo;
    this->repo.init_data();
}

Service::~Service()
{
    
}

void Service::init_data()
{
    this->repo.re_init_data();
}

int Service::get_table_dim()
{
    return this->repo.get_table_dim();
}

CellState Service::get(int x, int y)
{
    return this->repo.get(x, y);
}

bool Service::check_winner()
{
    bool win = false;
    int check = 0;
    for (int i = 0; i < this->get_table_dim(); i++)
        for (int j = 0; j < this->get_table_dim(); j++)
            if (this->repo.get(i, j) == CellState::Ship)
                check = 1;
    if (check == 0)
        win = true;
    return win;
}

bool Service::check_cell_free(int x, int y)
{
    bool free = true;
    if (this->repo.get(x, y) != CellState::Water)
        free = false;
    return free;
}

bool Service::check_cell_free_for_fire(int x, int y)
{
    bool free = false;
    if ((this->repo.get(x, y) == CellState::Water) || (this->repo.get(x, y) == CellState::Ship))
        free = true;
    return free;
}

void Service::make_move(int x, int y, CellState state)
{
    this->repo.update(x, y, state);
}

void Service::random_move()
{
    pair<int, int> random_move = this->generate_move();
    this->make_move(random_move.first, random_move.second, CellState::Hit);
}

pair<int, int> Service::generate_move()
{
    int randomX, randomY;
        do {
            randomX= rand() % (this->get_table_dim());
            randomY = rand() % (this->get_table_dim());
        } while (!this->check_cell_free_for_fire(randomX, randomY));
    
        return make_pair(randomX, randomY);
}
