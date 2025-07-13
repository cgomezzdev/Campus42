/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:53:45 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/07/08 17:53:46 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class PhoneBook {
public:
    PhoneBook();

    void AddContact(const Contact &contact);
    void DisplayContacts() const;
    void ShowContactDetails(int index) const;

private:
    Contact _contacts[8];
    int     _count;
    int     _oldestIndex;
};

#endif

