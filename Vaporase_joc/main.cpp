//
//  main.cpp
//  Vaporase_joc
//
//  Created by Comsa Mihai on 03/06/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#include <iostream>
#include "UI.hpp"
#include "TestRepo.hpp"
#include "TestService.hpp"

using namespace std;

int main()
{
    TestRepo test_repo;
    test_repo.test_all();
    
    TestService test_service;
    test_service.test_all();
    
    Repo repo_1(10), repo_2(10);
    Service serv_1(repo_1), serv_2(repo_2);
    UI ui(serv_1, serv_2);
    ui.start_game();
    
    return 0;
}
