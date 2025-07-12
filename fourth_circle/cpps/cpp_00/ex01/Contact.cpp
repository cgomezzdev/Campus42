/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:53:31 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/07/08 17:53:33 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::SetFirstName(const std::string &firstName){
    _firstName = firstName;
}

void Contact::SetLastName (const std::string &lastName){
    _lastName = lastName;
}

void Contact::SetNicknName(const std::string &nickName){
    _nickName = nicName;
}

void Contact::SetPhoneNumber(const std:: string &phoneNumber){
    _phoneNumber = phoneNumber;
}

void Contact::SetDarkestSecret (const std::string &darkestSecret){
    _darkestSecret = darkestSecret;
}

std::string GetFirstName() const{
    return _firstName;
}

std::string GetLastName() const {
    return _lastName;
}

std::string GetNickname() const {
    return _nickName;
}

std::string GetPhoneNumber () const {
    return _phoneNumber;
}

std::string GetDarkestSecret() const {
    return _darkestSecret;
}