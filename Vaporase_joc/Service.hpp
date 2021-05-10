//
//  Service.hpp
//  Vaporase_joc
//
//  Created by Comsa Mihai on 03/06/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#pragma once
#include "Repo.hpp"

class Service
{
private:
    Repo repo;
public:
    Service();
    Service(Repo repo);
    ~Service();
    void init_data();
    int get_table_dim();
    CellState get(int x, int y);
    bool check_winner();
    bool check_cell_free(int x, int y);
    bool check_cell_free_for_fire(int x, int y);
    void random_move();
    void make_move(int x, int y, CellState state);
    pair<int, int> generate_move();
};
