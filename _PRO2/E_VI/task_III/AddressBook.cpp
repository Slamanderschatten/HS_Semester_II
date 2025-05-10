//
// Created on 10.05.2025.
//

#include "AddressBook.h"

namespace hs_pro_II {




    /******************************************************/
    /************* private *******************************/
    /****************************************************/


    vector<shared_ptr<Person>>::iterator AddressBook::findPerson(const string& firstName, const string& lastName) {
        auto personsEndIt = persons.end();
        for(auto personIt = persons.begin(); personIt != personsEndIt; ++personIt) {
            if((*personIt)->equalsName(firstName, lastName)) {
                return personIt;
            }
        }
        return personsEndIt;
    }






    /******************************************************/
    /************* public ********************************/
    /****************************************************/


    const Person& AddressBook::addPerson(const string& firstName, const string& lastName) {
        persons.emplace_back(make_shared<Person>(firstName, lastName));
        return *persons.back();
    }
    const Person& AddressBook::addPerson(string&& firstName, string&& lastName) {
        persons.emplace_back(make_shared<Person>(firstName, lastName));
        return *persons.back();
    }


    shared_ptr<Person> AddressBook::getPerson(const string& firstName, const string& lastName) {
        return *findPerson(firstName, lastName);
    }
    shared_ptr<Person> AddressBook::getPerson(string&& firstName, string&& lastName) {
        return *findPerson(firstName, lastName);
    }


    void AddressBook::removePerson(const string& firstName, const string& lastName) {
        persons.erase(findPerson(firstName, lastName));
    }
    void AddressBook::removePerson(string&& firstName, string&& lastName) {
        persons.erase(findPerson(firstName, lastName));
    }









} // hs_pro_II