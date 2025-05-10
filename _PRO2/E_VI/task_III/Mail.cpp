//
// Created on 10.05.2025.
//

#include "Mail.h"

#include <utility>

namespace hs_pro_II {




    /******************************************************/
    /************* private *******************************/
    /****************************************************/






    /******************************************************/
    /************* public ********************************/
    /****************************************************/


    Mail::Mail(shared_ptr<Person> sender, shared_ptr<Person> recipient, string body):
            sender(std::move(sender)),
            recipient(std::move(recipient)),
            body(std::move(body)){
    }


    shared_ptr<Person> Mail::getSender() const {
        return sender;
    }


    shared_ptr<Person> Mail::getRecipient() const {
        return recipient;
    }


    const string& Mail::getBody() const {
        return body;
    }







} // hs_pro_II