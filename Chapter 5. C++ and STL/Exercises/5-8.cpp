// 题目 UVa 230 ：https://cn.vjudge.net/problem/UVA-230

#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;

struct Book
{
    string name, author; // 书名、作者
    Book(string name = "", string author = "") : name(name), author(author) {}
};

vector<Book> books;                // 书架上的书
stack<string> returnedBookStr;     // 归还的书
map<string, string> borrowedBooks; // 借出去的书

// book1比boo2小，返回true；否则，返回false
bool compare(const Book &book1, const Book &book2)
{
    if (book1.author < book2.author)
    {
        return true;
    }
    else if (book1.author > book2.author)
    {
        return false;
    }
    else
    {
        if (book1.name <= book2.name)
        {
            return true;
        }
        else if (book1.name > book2.name)
        {
            return false;
        }
    }
}

bool compareAuthor(const Book &book1, const Book &book2)
{
    return book1.author < book2.author;
}

bool compareName(const Book &book1, const Book &book2)
{
    return book1.name < book2.name;
}

void changeToBook(const string &input, Book &book)
{
    string name = input.substr(input.find('\"') + 1, input.find_last_of('\"') - input.find('\"') - 1);
    string author = input.substr(input.find("by ") + 3);
    book.name = name;
    book.author = author;
}

string getBookName(const string &input)
{
    return input.substr(input.find('\"') + 1, input.find_last_of('\"') - input.find('\"') - 1);
}

void borrowBook(const string &bookName)
{
    vector<Book>::iterator it;
    for (it = books.begin(); it != books.end(); ++it)
    {
        if (it->name == bookName)
        {
            borrowedBooks[it->name] = it->author;
            books.erase(it);
            break;
        }
    }
}

void returnBook(const string &bookName)
{
    Book book(bookName, borrowedBooks[bookName]);
    vector<Book>::iterator it;
    for (it = books.begin(); it != books.end(); ++it)
    {
        if (compare(book, *it))
        {
            string str;
            if (it == books.begin())
            {
                str = "Put \"" + book.name + "\" first";
            }
            else if (it == books.end() - 1)
            {
                str = "Put \"" + book.name + "\" after \"" + it->name + "\"";
            }
            else
            {
                str = "Put \"" + book.name + "\" after \"" + (it - 1)->name + "\"";
            }
            returnedBookStr.push(str);
            books.insert(it, book);
            break;
        }
    }
}

int main() {
    string input;
    while (getline(cin, input) && input.at(0) != 'E')
    {
        Book book;
        changeToBook(input, book);
        books.push_back(book);
    }
    //    sort(books.begin(), books.end(), compare);
    sort(books.begin(), books.end(), compareAuthor);
    sort(books.begin(), books.end(), compareName);
    vector<Book>::iterator it1;
    for (it1 = books.begin(); it1 != books.end(); ++it1)
    {
        cout << it1->name << endl;
    }

    while (getline(cin, input))
    {
        int operation = input.at(0);
        if (operation == 'B')
        { // 借书
            string bookName = getBookName(input);
            borrowBook(bookName);
        }
        else if (operation == 'R')
        {
            string name = getBookName(input);
            returnBook(name);
        }
        else if (operation == 'S')
        {
            vector<string>::iterator it;
            while (!returnedBookStr.empty())
            {
                cout << returnedBookStr.top() << endl;
                returnedBookStr.pop();
            }
            cout << "END" << endl;
        }
        else
        {
            break;
        }
    }

    return 0;
}