//
//  TestService.cpp
//  Vaporase_joc
//
//  Created by Comsa Mihai on 04/06/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#include "TestService.hpp"
#include <iostream>
#include "Service.hpp"
#include "Repo.hpp"
#include <cassert>
#include "RepoException.hpp"

using namespace std;

void TestService::test_init_data()
{
    Repo repo(3);
    Service serv(repo);
    serv.make_move(1, 1, CellState::Ship);
    serv.init_data();
    
    for (int i = 0; i < serv.get_table_dim(); i++)
        for (int j = 0; j < serv.get_table_dim(); j++)
            assert(serv.get(i, j) == CellState::Water);
}

void TestService::test_get_table_dim()
{
    Repo repo(1);
    Service serv(repo);
    Repo repo2(5);
    Service serv2(repo2);
    Repo repo3(10);
    Service serv3(repo3);
    
    assert(serv.get_table_dim() == 1);
    assert(serv2.get_table_dim() == 5);
    assert(serv3.get_table_dim() == 10);
}

void TestService::test_get()
{
    Repo repo(3);
    Service serv(repo);
    
    try
    {
        assert(serv.get(0, 0) == CellState::Water);
        serv.make_move(0, 0, CellState::Ship);
        assert(serv.get(0, 0) == CellState::Ship);
    }
    catch (...)
    {
        assert(false);
    }
    
    try
    {
        serv.get(-1, 0);
        assert(false);
    }
    catch (RepoException & e) {}
    catch (...)
    {
        assert(false);
    }
    
    try
    {
        serv.get(0, -1);
        assert(false);
    }
    catch (RepoException & e) {}
    catch (...)
    {
        assert(false);
    }
    
    try
    {
        serv.get(-1, -1);
        assert(false);
    }
    catch (RepoException & e) {}
    catch (...)
    {
        assert(false);
    }
    
    try
    {
        serv.get(4, 0);
        assert(false);
    }
    catch (RepoException & e) {}
    catch (...)
    {
        assert(false);
    }
    
    try
    {
        serv.get(0, 4);
        assert(false);
    }
    catch (RepoException & e) {}
    catch (...)
    {
        assert(false);
    }
    
    try
    {
        serv.get(4, 4);
        assert(false);
    }
    catch (RepoException & e) {}
    catch (...)
    {
        assert(false);
    }
    
    try
    {
        serv.get(-1, 4);
        assert(false);
    }
    catch (RepoException & e) {}
    catch (...)
    {
        assert(false);
    }
}

void TestService::test_check_free()
{
    Repo repo(3);
    Service serv(repo);
    
    for (int i = 0; i < serv.get_table_dim(); i++)
        for (int j = 0; j < serv.get_table_dim(); j++)
            assert(serv.check_cell_free(i, j));
    
    serv.make_move(0, 1, CellState::Ship);
    serv.make_move(2, 0, CellState::Ship);
    
    assert(serv.check_cell_free(0, 1) == false);
    assert(serv.check_cell_free(2, 0) == false);
}

void TestService::test_check_free_for_fire()
{
    Repo repo(3);
    Service serv(repo);
    
    for (int i = 0; i < serv.get_table_dim(); i++)
        for (int j = 0; j < serv.get_table_dim(); j++)
            assert(serv.check_cell_free_for_fire(i, j));
    
    serv.make_move(0, 1, CellState::Ship);
    serv.make_move(2, 0, CellState::Ship);
    serv.make_move(0, 0, CellState::Ship);
    serv.make_move(0, 0, CellState::Hit);
    serv.make_move(1, 1, CellState::Hit);
    
    assert(serv.check_cell_free_for_fire(0, 1) == true);
    assert(serv.check_cell_free_for_fire(2, 0) == true);
    assert(serv.check_cell_free_for_fire(0, 0) == false);
    assert(serv.check_cell_free_for_fire(1, 1) == false);
}

void TestService::test_check_winner()
{
    Repo repo(3), repo2(3);
    Service serv(repo), serv2(repo2);
    
    serv.make_move(0, 2, CellState::Ship);
    serv2.make_move(1, 1, CellState::Ship);
    serv2.make_move(1, 1, CellState::Hit);
    
    assert(serv.check_winner() == false);
    assert(serv2.check_winner() == true);
}

void TestService::test_make_move()
{
    Repo repo(3);
    Service serv(repo);
    
    serv.make_move(0, 0, CellState::Ship);
    serv.make_move(1, 1, CellState::Hit);
    serv.make_move(1, 2, CellState::Ship);
    serv.make_move(1, 2, CellState::Hit);
    
    assert(serv.get(0, 0) == CellState::Ship);
    assert(serv.get(1, 1) == CellState::Missed);
    assert(serv.get(1, 2) == CellState::Hit);
    
    try
    {
        serv.make_move(-1, 0, CellState::Hit);
        assert(false);
    }
    catch (RepoException & e) {}
    catch (...)
    {
        assert(false);
    }
    
    try
    {
        serv.make_move(0, -1, CellState::Hit);
        assert(false);
    }
    catch (RepoException & e) {}
    catch (...)
    {
        assert(false);
    }
    
    try
    {
        serv.make_move(-1, -1, CellState::Hit);
        assert(false);
    }
    catch (RepoException & e) {}
    catch (...)
    {
        assert(false);
    }
    
    try
    {
        serv.make_move(4, 0, CellState::Hit);
        assert(false);
    }
    catch (RepoException & e) {}
    catch (...)
    {
        assert(false);
    }
    
    try
    {
        serv.make_move(0, 4, CellState::Hit);
        assert(false);
    }
    catch (RepoException & e) {}
    catch (...)
    {
        assert(false);
    }
    
    try
    {
        serv.make_move(4, 4, CellState::Hit);
        assert(false);
    }
    catch (RepoException & e) {}
    catch (...)
    {
        assert(false);
    }
    
    try
    {
        serv.make_move(4, -1, CellState::Hit);
        assert(false);
    }
    catch (RepoException & e) {}
    catch (...)
    {
        assert(false);
    }
}

void TestService::test_random_move()
{
    Repo repo(3);
    Service serv(repo);
    int nr = 0;
    
    serv.random_move();
    serv.random_move();
    
    for (int i = 0; i < serv.get_table_dim(); i++)
        for (int j = 0; j < serv.get_table_dim(); j++)
            if (serv.get(i, j) == CellState::Missed)
                nr += 1;
    
    assert(nr == 2);
}

TestService::TestService()
{
}

TestService::~TestService()
{
}

void TestService::test_all()
{
    test_init_data();
    test_get();
    test_get_table_dim();
    test_check_free();
    test_check_free_for_fire();
    test_check_winner();
    test_make_move();
    test_random_move();
}
