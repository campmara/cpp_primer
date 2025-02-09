/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
 * Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 *
 * "Copyright (c) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E. Moo."
 *
 *
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 *
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address:
 *
 *     Pearson Education, Inc.
 *     Rights and Permissions Department
 *     One Lake Street
 *     Upper Saddle River, NJ  07458
 *     Fax: (201) 236-3290
 */

/* This file defines the Sales_item class used in chapter 1.
 * The code used in this file will be explained in
 * Chapter 7 (Classes) and Chapter 14 (Overloaded Operators)
 * Readers shouldn't try to understand the code in this file
 * until they have read those chapters.
 */

#ifndef SALES_ITEM_H
// we're here only if SALESITEM_H has not yet been defined
#define SALES_ITEM_H

#include "version_test.h"

// Definition of Sales_item class and related functions goes here
#include <iostream>
#include <string>

class SalesItem
{
    // these declarations are explained section 7.2.1, p. 270
    // and in chapter 14, pages 557, 558, 561
    friend std::istream &operator>>(std::istream &, SalesItem &);
    friend std::ostream &operator<<(std::ostream &, const SalesItem &);
    friend bool operator<(const SalesItem &, const SalesItem &);
    friend bool operator==(const SalesItem &, const SalesItem &);

public:
    // constructors are explained in section 7.1.4, pages 262 - 265
    // default constructor needed to initialize members of built-in type
#if defined(IN_CLASS_INITS) && defined(DEFAULT_FCNS)
    Sales_item() = default;
#else
    SalesItem() : units_sold(0), revenue(0.0) {}
#endif
    SalesItem(const std::string &book) : isbn(book), units_sold(0), revenue(0.0) {}
    SalesItem(std::istream &is)
    {
        is >> *this;
    }

public:
    // operations on Sales_item objects
    // member binary operator: left-hand operand bound to implicit this pointer
    SalesItem &operator+=(const SalesItem &);

    // operations on Sales_item objects
    std::string get_isbn() const
    {
        return isbn;
    }
    double avg_price() const;
    unsigned get_units_sold() const
    {
        return units_sold;
    }
    // private members as before
private:
    std::string isbn; // implicitly initialized to the empty string
#ifdef IN_CLASS_INITS
    unsigned units_sold = 0; // explicitly initialized
    double revenue = 0.0;
#else
    unsigned units_sold;
    double revenue;
#endif
};

// used in chapter 10
inline bool compareIsbn(const SalesItem &lhs, const SalesItem &rhs)
{
    return lhs.get_isbn() == rhs.get_isbn();
}

// nonmember binary operator: must declare a parameter for each operand
SalesItem operator+(const SalesItem &, const SalesItem &);

inline bool operator==(const SalesItem &lhs, const SalesItem &rhs)
{
    // must be made a friend of Sales_item
    return lhs.units_sold == rhs.units_sold && lhs.revenue == rhs.revenue &&
           lhs.get_isbn() == rhs.get_isbn();
}

inline bool operator!=(const SalesItem &lhs, const SalesItem &rhs)
{
    return !(lhs == rhs); // != defined in terms of operator==
}

// assumes that both objects refer to the same ISBN
SalesItem &SalesItem::operator+=(const SalesItem &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

// assumes that both objects refer to the same ISBN
SalesItem operator+(const SalesItem &lhs, const SalesItem &rhs)
{
    SalesItem ret(lhs); // copy (|lhs|) into a local object that we'll return
    ret += rhs;         // add in the contents of (|rhs|)
    return ret;         // return (|ret|) by value
}

std::istream &operator>>(std::istream &in, SalesItem &s)
{
    double price;
    in >> s.isbn >> s.units_sold >> price;
    // check that the inputs succeeded
    if (in)
        s.revenue = s.units_sold * price;
    else
        s = SalesItem(); // input failed: reset object to default state
    return in;
}

std::ostream &operator<<(std::ostream &out, const SalesItem &s)
{
    out << s.get_isbn() << " " << s.units_sold << " " << s.revenue << " " << s.avg_price();
    return out;
}

double SalesItem::avg_price() const
{
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}
#endif
