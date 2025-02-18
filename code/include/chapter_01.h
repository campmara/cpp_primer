#ifndef CHAPTER_01_H
#define CHAPTER_01_H

#include <iostream>

#include "sales_item.h"

void exercise_1_4()
{
    std::cout << "Enter two numbers: " << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The sum of " << v1 << " and " << v2 << " is " << v1 * v2 << std::endl;
}

void exercise_1_5()
{
    std::cout << "Enter two numbers: " << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The sum of ";
    std::cout << v1;
    std::cout << " and ";
    std::cout << v2;
    std::cout << " is ";
    std::cout << v1 * v2;
    std::cout << std::endl;
}

void exersise_1_8()
{
    std::cout << "/*";
    std::cout << "*/";
    std::cout << /* "*/ " */ ";
    std::cout << /* "*/ " /* " /*" */;
}

void exercise_1_9()
{
    int i = 50;
    int sum = 0;

    while (i <= 100)
    {
        sum += i;
        std::cout << "sum is: " << sum << std::endl;
        i++;
    }
}

void exercise_1_10()
{
    int i = 10;

    while (i >= 0)
    {
        std::cout << i << std::endl;
        i--;
    }
}

void exercise_1_11()
{
    int num1, num2;

    std::cout << "please enter two integers: ";
    std::cin >> num1 >> num2;

    if (num1 == num2)
    {
        std::cout << num1 << std::endl;
    }
    else if (num1 < num2)
    {
        int i = num1;
        while (i <= num2)
        {
            std::cout << i << std::endl;
            i++;
        }
    }
    else
    {
        int i = num2;
        while (i <= num1)
        {
            std::cout << i << std::endl;
            i++;
        }
    }
}

void exercise_1_12()
{
    int sum = 0;
    for (int i = -100; i <= 100; ++i)
    {
        sum += i;
    }
    std::cout << sum << std::endl;
}

void exercise_1_13()
{
    // exercise_1_9
    int sum = 0;
    for (int i = 50; i <= 100; ++i)
    {
        sum += i;
        std::cout << "sum is: " << sum << std::endl;
    }

    // exercise_1_10
    for (int i = 10; i >= 0; --i)
    {
        std::cout << i << std::endl;
    }
}

void exercise_1_16()
{
    int sum = 0;
    int currentValue;

    std::cout << "Please enter a set of integers: ";

    while (std::cin >> currentValue)
    {
        sum += currentValue;
    }

    std::cout << std::endl << "sum: " << sum << std::endl;
}

void exercise_1_17()
{
    int current_value = 0, value = 0;

    if (std::cin >> current_value)
    {
        int count = 1;
        while (std::cin >> value)
        {
            if (value == current_value)
            {
                ++count;
            }
            else
            {
                std::cout << current_value << " occurs " << count << " times" << std::endl;
                current_value = value;
                count = 1;
            }
        }
        std::cout << current_value << " occurs " << count << " times" << std::endl;
    }
}

void exercise_1_20()
{
    SalesItem book;

    while (std::cin >> book)
    {
        std::cout << book << std::endl;
    }
}

void exercise_1_21()
{
    SalesItem item1, item2;
    std::cin >> item1 >> item2;

    std::cout << "sum: " << item1 + item2 << std::endl;
}

void exercise_1_22()
{
    SalesItem item, readValue;
    double sum = 0.0;
    while (std::cin >> readValue)
    {
        item += readValue;
    }

    std::cout << "sum of all transactions: " << item << std::endl;
}

void exercise_1_23()
{
    SalesItem current_item, item;

    if (std::cin >> current_item)
    {
        while (std::cin >> item)
        {
            if (item.get_isbn() == current_item.get_isbn())
            {
                current_item += item;
            }
            else
            {
                std::cout << "isbn: " << current_item.get_isbn() << " sold "
                          << current_item.get_units_sold() << " copies." << std::endl;
                current_item = item;
            }
        }
        std::cout << "isbn: " << current_item.get_isbn() << " sold "
                  << current_item.get_units_sold() << " copies." << std::endl;
    }
}

int bookstore_program()
{
    SalesItem total;

    if (std::cin >> total)
    {
        SalesItem trans;

        while (std::cin >> trans)
        {
            if (total.get_isbn() == trans.get_isbn())
            {
                total += trans;
            }
            else
            {
                std::cout << total << std::endl;
                total = trans;
            }
        }
        std::cout << total << std::endl;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}

#endif // !CHAPTER_01_H
