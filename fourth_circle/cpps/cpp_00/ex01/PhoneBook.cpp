/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:53:19 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/07/08 17:53:21 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip> // para std::setw

PhoneBook::PhoneBook() {
    _count = 0;
    _oldestIndex = 0;
}

void PhoneBook::AddContact(const Contact &contact) {
    _contacts[_oldestIndex] = contact;

    _oldestIndex = (_oldestIndex + 1) % 8;

    if (_count < 8)
        _count++;
}

void PhoneBook::DisplayContacts() const {
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "FirstName" << "|"
              << std::setw(10) << "LastName" << "|"
              << std::setw(10) << "NickName" << "|"
              << std::setw(10) << "PhoneNumber" << std::endl;

    for (int i = 0; i < _count; i++) {
        std::cout << std::setw(10) << i << "|"
                << std::setw(10) << FormatField(_contacts[i].GetIndex()) << "|"
                  << std::setw(10) << FormatField(_contacts[i].GetFirstName()) << "|"
                  << std::setw(10) << FormatField(_contacts[i].GetLastName()) << "|"
                  << std::setw(10) << FormatField(_contacts[i].GetNickname()) << "|"
                  << std::setw(10) << FormatField(_contacts[i].GetPhoneNumber()) << "|"  
                  << std::setw(10) << FormatField(_contacts[i].GetDarkestSecret()) << std::endl;
    }
}

// Esta función ayuda a truncar si es muy largo
std::string PhoneBook::FormatField(const std::string &str) const {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}