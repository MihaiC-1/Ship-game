//
//  Repo.cpp
//  Vaporase_joc
//
//  Created by Comsa Mihai on 03/06/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#include "Repo.hpp"
#include "RepoException.hpp"

Repo::Repo()
{
    this->table = 0;
}

Repo::Repo(int table)
{
    this->table = table;
    this->init_data();
}

Repo::~Repo()
{
    
}

void Repo::init_data()
{
    for (int i = 0; i < this->table; i++)
    {
        for (int j = 0; j < this->table; j++)
        {
            this->add(i, j, CellState::Water);
        }
    }
}

void Repo::re_init_data()
{
    for (int i = 0; i < this->table; i++)
    {
        for (int j = 0; j < this->table; j++)
        {
            this->update(i, j, CellState::Water);
        }
    }
}

int Repo::get_table_dim()
{
    return this->table;
}

CellState Repo::get(int x, int y)
{
    if ((x < 0) || (x >= this->table) || (y < 0) || (y >= this->table))
    {
        throw RepoException("Coordonatele scrise nu sunt valide.\n");
    }
    return this->Cell[make_pair(x, y)];
}

void Repo::add(int x, int y, CellState state)
{
    this->Cell.insert({ make_pair(x, y), state});
}

void Repo::update(int x, int y, CellState state)
{
    if ((x < 0) || (x >= this->table) || (y < 0) || (y >= this->table))
    {
        throw RepoException("Coordonatele scrise nu sunt valide.\n");
    }
    
    if (state == CellState::Ship || state == CellState::Water)
    {
        this->Cell[make_pair(x, y)] = state;
    }
    else
    {
        if (this->get(x, y) == CellState::Ship)
            this->Cell[make_pair(x, y)] = state;
        else
            this->Cell[make_pair(x, y)] = CellState::Missed;
    }
}
