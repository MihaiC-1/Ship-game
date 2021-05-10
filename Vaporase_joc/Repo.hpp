//
//  Repo.hpp
//  Vaporase_joc
//
//  Created by Comsa Mihai on 03/06/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#include <stdio.h>
#pragma once
#include <map>
#include "CellState.hpp"

using namespace std;

class Repo
{
private:
    map<pair<int, int>, CellState> Cell;
    int table;
public:
    Repo();
    Repo(int table);
    ~Repo();
    void init_data();
    int get_table_dim();
    CellState get(int x, int y);
    void add(int x, int y, CellState state);
    void update(int x, int y, CellState state);
    void re_init_data();
};

