//
//  TestRepo.cpp
//  Vaporase_joc
//
//  Created by Comsa Mihai on 04/06/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#include "TestRepo.hpp"
#include <iostream>
#include <cassert>
#include "Repo.hpp"
#include "RepoException.hpp"

using namespace std;

void TestRepo::test_init_data()
{
    Repo repo(3);
    repo.init_data();
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            assert(repo.get(i, j) == CellState::Water);
}

void TestRepo::test_get_table_dim()
{
    Repo repo_1;
    Repo repo_2(5);
    Repo repo_3(10);
    
    assert(repo_1.get_table_dim() == 0);
    assert(repo_2.get_table_dim() == 5);
    assert(repo_3.get_table_dim() == 10);
}

void TestRepo::test_re_init_data()
{
    Repo repo(3);
    
    repo.update(1, 1, CellState::Ship);
    repo.re_init_data();
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j< 3; j++)
            assert(repo.get(i, j) == CellState::Water);
}

void TestRepo::test_get()
{
    Repo repo(3);
    
    try
    {
        assert(repo.get(1, 1) == CellState::Water);
        repo.update(1, 1, CellState::Ship);
        assert(repo.get(1, 1) == CellState::Ship);
    }
    catch (...)
    {
        assert(false);
    }
    
    try
    {
        repo.get(-1, 0);
        assert(false);
    }
    catch (RepoException& e) {}
    catch (...)
    {
        assert(false);
    }
    
    try
    {
        repo.get(0, -1);
        assert(false);
    }
    catch (RepoException& e) {}
    catch (...)
    {
        assert(false);
    }
    
    try
    {
        repo.get(-1, -1);
        assert(false);
    }
    catch (RepoException& e) {}
    catch (...)
    {
        assert(false);
    }
    
    try
    {
        repo.get(1, 4);
        assert(false);
    }
    catch (RepoException& e) {}
    catch (...)
    {
        assert(false);
    }
    
    try
    {
        repo.get(4, 1);
        assert(false);
    }
    catch (RepoException& e) {}
    catch (...)
    {
        assert(false);
    }
    
    try
    {
        repo.get(-1, 4);
        assert(false);
    }
    catch (RepoException& e) {}
    catch (...)
    {
        assert(false);
    }
}

void TestRepo::test_add()
{
    //Nu se poate verifica. Tabla este deja creata complet la initializare.
}

void TestRepo::test_update()
{
    Repo repo(3);
    
    try
    {
        repo.update(1, 1, CellState::Ship);
        assert(repo.get(1, 1) == CellState::Ship);
    }
    catch (...) {
        assert(false);
    }
    
    try
    {
        repo.update(-1, 1, CellState::Ship);
    }
    catch (RepoException& e) {}
    catch (...) {
        assert(false);
    }
    
    try
    {
        repo.update(1, -1, CellState::Ship);
    }
    catch (RepoException& e) {}
    catch (...) {
        assert(false);
    }
    
    try
    {
        repo.update(4, 1, CellState::Ship);
    }
    catch (RepoException& e) {}
    catch (...) {
        assert(false);
    }
    
    try
    {
        repo.update(1, 4, CellState::Ship);
    }
    catch (RepoException& e) {}
    catch (...) {
        assert(false);
    }
    
    try
    {
        repo.update(4, 4, CellState::Ship);
    }
    catch (RepoException& e) {}
    catch (...) {
        assert(false);
    }
    
    try
    {
        repo.update(-1, 4, CellState::Ship);
    }
    catch (RepoException& e) {}
    catch (...) {
        assert(false);
    }
}

TestRepo::TestRepo()
{
}

TestRepo::~TestRepo()
{
}

void TestRepo::test_all()
{
    test_init_data();
    test_get_table_dim();
    test_get();
    test_add();
    test_re_init_data();
    test_update();
}
