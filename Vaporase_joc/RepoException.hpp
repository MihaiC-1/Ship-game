//
//  RepoException.hpp
//  Vaporase_joc
//
//  Created by Comsa Mihai on 03/06/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#pragma once
#include <stdio.h>
#include <string>

class RepoException : public exception
{
private:
    string message;
public:
    RepoException(const string message)
        {
            this->message = message;
        }
    
        ~RepoException()
        {
            this->message = " ";
        }
    
        virtual const string what()
        {
            return message;
        }
};
