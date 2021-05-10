//
//  TestService.hpp
//  Vaporase_joc
//
//  Created by Comsa Mihai on 04/06/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#pragma once

class TestService
{
private:
    void test_init_data();
    void test_get();
    void test_get_table_dim();
    void test_check_free();
    void test_check_free_for_fire();
    void test_check_winner();
    void test_make_move();
    void test_random_move();
public:
    TestService();
    ~TestService();
    void test_all();
};
