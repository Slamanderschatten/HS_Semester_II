//
// Created on 10.05.2025.
//

#include "Person.h"

#include <utility>

namespace hs_pro_II {




    /******************************************************/
    /************* private *******************************/
    /****************************************************/






    /******************************************************/
    /************* public ********************************/
    /****************************************************/


    Person::Person(std::string firstName, std::string lastName) :
            firstName(std::move(firstName)),
            lastName(std::move(lastName))
    {

    }


    bool Person::equalsName(string compName, string compSurname) {
        return std::equal(firstName.begin(), firstName.end(), compName.begin(), compName.end()) && std::equal(lastName.begin(), lastName.end(), compSurname.begin(), compSurname.end());
    }


    void Person::addFriend(const shared_ptr<Person>& newFriend) {
        friends.push_back(newFriend);
    }


    void Person::printFriends() {
        cout << "friends of " << getFullName() << ": ";
        for(weak_ptr<Person>& friendWP : friends) {
            shared_ptr<Person> friendSP = friendWP.lock();
            cout << friendSP->getFullName() << ", ";
        }
    }


    string Person::getFirstName() const {
        return firstName;
    }


    string Person::getLastName() const {
        return lastName;
    }


    string Person::getFullName() const {
        return firstName + " " + lastName;
    }







} // hs_pro_II