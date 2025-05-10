//
// Created on 10.05.2025.
//

#pragma once

#include "../../_MAIN.h"
#include "Person.h"

namespace hs_pro_II {

    class AddressBook {
    private:
        vector<shared_ptr<Person>> persons;


        vector<shared_ptr<Person>>::iterator findPerson(const string& firstName, const string& lastName);


    public:

        const Person& addPerson(const string& firstName, const string& lastName);
        const Person& addPerson(string&& firstName, string&& lastName);
        shared_ptr<Person> getPerson(const string& firstName, const string& lastName);
        shared_ptr<Person> getPerson(string&& firstName, string&& lastName);
        void removePerson(const string& firstName, const string& lastName);
        void removePerson(string&& firstName, string&& lastName);

    };

} // hs_pro_II
