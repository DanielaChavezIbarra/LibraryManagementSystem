#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"
#include "Member.h"
#include "Loan.h"
#include "CD.h"

using namespace std;

class Library {
private:
    vector<Book> books;
    vector<Member> members;
    vector<Loan> loans;
    vector<CD> cds;

    Book* findBook(const string& isbn);
    CD* findCD(const string& upc);
    Member* findMember(const string& memberId);
    int countActiveLoansForMember(const string& memberId) const;
    bool isBookAvailable(const string& isbn) const;
    Loan* findActiveLoan(const string& memberId, const string& isbn);

public:
    void addBook(const Book& book);
    void addCD(const CD& cd);
    void addMember(const Member& member);
    void listBooks() const;
    void listCDs() const;
    void listMembers() const;
    void listLoans(bool onlyActive = false) const;
    bool borrowBook(const string& memberId, const string& isbn, const string& borrowDate);
    bool returnBook(const string& memberId, const string& isbn, const string& returnDate);
    bool removeBook(const string& isbn);
    bool removeMember(const string& memberId);
    Book* getBookByISBN(const string& isbn);
    Book* getBookByTitle(const string& title);
};

#endif // LIBRARY_H

