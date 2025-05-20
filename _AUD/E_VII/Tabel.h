//
// Created on 20.05.2025.
//

#pragma once

#include <cinttypes>

namespace hs_aud {

    template<typename itemType>
    class Table {
    private:
        struct node
        {
            itemType item;
            node *next;
            node *before;

            node(itemType e, node* before, node* next) : item(e), before(before), next(next) {}
        };


        node* begin = nullptr;
        node* record = nullptr;
        node* end = nullptr;

    public:
        Table() = default;
        ~Table() {
            clear();
        }
        bool insert(itemType r) {
            if(record) {
                node *before = record->before;
                record->before = new node(r, before, record);
                if (before == nullptr)
                    begin = record->before;
            } else {
                record = new node(r, nullptr, nullptr);
                begin = record;
                end = record;
            }
            return true;
        }
        bool append(itemType r) {
            if(end) {
                end->next = new node(r, end, nullptr);
                end = end->next;
            } else {
                record = new node(r, nullptr, nullptr);
                begin = record;
                end = record;
            }
            return true;
        }
        bool first() {
            record = begin;
            return record;
        }
        bool last() {
            record = end;
            return record;
        }
        bool next() {
            if(!record || !record->next)
                return false;
            record = record->next;
            return true;
        }
        bool previous() {
            if(!record || !record->before)
                return false;
            record = record->before;
            return true;
        }
        bool erase() {
            if(!record)
                return false;
            node* before = record->before;
            node* next = record->next;
            delete record;

            if(next)
                next->before = before;
            else
                end = before;

            if(before) {
                before->next = next;
                record = before;
            }
            else {
                begin = next;
                record = next;
            }
            return true;
        }
        bool get(itemType& r) {
            if(!record)
                return false;
            r = record->item;
            return true;
        }
        bool set(itemType& r) {
            if(!record)
                return false;
            record->item = r;
            return true;
        }
        void clear() {
            if(!begin)
                return;
            node* toDelete = begin;
            while(toDelete->next) {
                toDelete = toDelete->next;
                delete toDelete->before;
            }
            delete end;
            begin = nullptr;
            end = nullptr;
            record = nullptr;
        }

    };

} // hs_aud
