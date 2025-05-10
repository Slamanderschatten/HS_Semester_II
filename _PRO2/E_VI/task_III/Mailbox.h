//
// Created on 10.05.2025.
//

#pragma once

#include "../../_MAIN.h"
#include "Mail.h"
#include "Person.h"

namespace hs_pro_II {

    class Mailbox {
    private:
        vector<shared_ptr<Mail>> mails;


    public:

        const Mail& addMail(shared_ptr<Person> sender, shared_ptr<Person> recipient, const string& body);
        void printStatus();


    };

} // hs_pro_II
