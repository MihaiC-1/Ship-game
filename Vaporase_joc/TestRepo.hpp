//
//  TestRepo.hpp
//  Vaporase_joc
//
//  Created by Comsa Mihai on 04/06/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#pragma once

class TestRepo
{
private:
    void test_init_data();
    void test_get_table_dim();
    void test_get();
    void test_add();
    void test_update();
    void test_re_init_data();
public:
    TestRepo();
    ~TestRepo();
    void test_all();
};
