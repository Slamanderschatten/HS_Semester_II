//
// Created on 06.05.2025.
//

#include <cinttypes>
#include <stdexcept>

#pragma once

namespace hs_aud {

    template<class item_type>
    class Stack {
        struct node
        {
            node(item_type e, node* next) : item(e), next(next) {}
            item_type item;
            node *next = nullptr;
        };
    private:
        node *tail = nullptr;
        size_t elemNumber = 0;
    public:
        Stack() = default;
        ~Stack() {
            clear();
        }
        void push(item_type &r) {
            node* next = nullptr;
            if(tail)
                next = tail;
            tail = new node(r, next);
            elemNumber++;
        }
        item_type pop() {
            if(!tail)
                throw std::out_of_range("stack is empty");

            item_type elem = tail->item;
            node* newTail = tail->next;
            delete tail;
            tail = newTail;

            elemNumber--;
            return elem;
        }
        item_type top() {
            if(tail)
                return tail->item;
            else throw std::out_of_range("stack is empty");
        }
        size_t size() {
            return elemNumber;
        }
        bool empty() {
            return elemNumber == 0;
        }
        void clear() {
            node* next = tail;
            while(next) {
                node* actualTail = next;
                next = next->next;
                delete actualTail;
            }
        }


    };

} // hs_aud
