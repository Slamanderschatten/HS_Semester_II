//
// Created on 10.05.2025.
//

#pragma once

#include "../../_MAIN.h"
#include "Person.h"

namespace hs_pro_II {

    class Mail {
    private:
        string body;
        shared_ptr<Person> sender;
        shared_ptr<Person> recipient;

    public:
        Mail() = delete;
        Mail(shared_ptr<Person> sender, shared_ptr<Person> recipient, string body);
        [[nodiscard]] shared_ptr<Person> getSender() const;
        [[nodiscard]] shared_ptr<Person> getRecipient() const;
        [[nodiscard]] const string& getBody() const;



    };

} // hs_pro_II
