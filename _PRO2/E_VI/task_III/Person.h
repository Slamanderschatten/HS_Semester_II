//
// Created on 10.05.2025.
//

#pragma once

#include "../../_MAIN.h"

namespace hs_pro_II {

    class Person {
    private:
        string firstName;
        string lastName;
        vector<weak_ptr<Person>> friends;

    public:

        Person() = delete;
        Person(string firstName, string lastName);
        bool equalsName(string compName, string compSurname);
        void addFriend(const shared_ptr<Person>& newFriend);
        void printFriends();
        [[nodiscard]] string getFirstName() const;
        [[nodiscard]] string getLastName() const;
        [[nodiscard]] string getFullName() const;


    };

} // hs_pro_II
