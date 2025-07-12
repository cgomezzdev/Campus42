/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:53:39 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/07/08 17:53:41 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {
public:
    void SetFirstName(const std::string &firstName);
    std::string GetFirstName() const;

    void SetLastName(const std::string &lastName);
    std::string GetLastName() const;

    void SetNickName(const std::string &nickName);
    std::string GetNickname() const;

    void SetPhoneNumber(const std::string &phoneNumber);
    std::string GetPhoneNumber() const;

    void SetDarkestSecret(const std::string &darkestSecret);
    std::string GetDarkestSecret() const;

private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickName
    std::string _phoneNumber;
    std::string _darkestSecret;
};

#endif