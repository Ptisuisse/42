#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>

class Contact
{
  public:
    Contact(void);
    ~Contact(void);
    std::string get_first_name(void);
    std::string get_last_name(void);
    std::string get_nickname(void);
    std::string get_phone(void);
    std::string get_dark(void);
    void    set_index(int index);
    void    set_first_name(std::string f_name);
    void    set_last_name(std::string l_name);
    void    set_nickname(std::string nick);
    void    set_phone_number(std::string phone);
    void    set_dark(std::string d_secret);
  private:
    int index;
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
};

// void    display_contact(Contact contact);

#endif