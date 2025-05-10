//
// Created on 10.05.2025.
//

#include "Mailbox.h"

namespace hs_pro_II {




    /******************************************************/
    /************* private *******************************/
    /****************************************************/






    /******************************************************/
    /************* public ********************************/
    /****************************************************/


    const Mail &Mailbox::addMail(shared_ptr<Person> sender,
                                 shared_ptr<Person> recipient,
                                 const string& body) {
        mails.emplace_back(make_shared<Mail>(sender, recipient, body));
        return *mails.back();
    }


    void Mailbox::printStatus() {

    }







} // hs_pro_II