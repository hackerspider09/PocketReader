// Header file Reader.h
#ifndef READER_H
#define READER_H

class Reader{
    private:
        int currentPage;
        int totalPages;
    public:
        Reader();

        void nextPage();
        void previousPage();
        void setTotalPages(int totalPages);
        int getCurrentPage();

};

#endif