// Library.h
#pragma once // Prevents duplicate inclusion errors

#include <string>
#include <vector>
#include "Book.h"

class Library{
    private:
        std::vector<Book> books;
    public:
        Library();
        void addBook(Book book);
        int getBookCount();
        Book* getBook(int idx); // later will use <optional>
        std::vector<Book> listBooks();
};