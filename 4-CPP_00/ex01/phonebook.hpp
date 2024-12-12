/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   phonebook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 13:45:53 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/12/10 17:34:17 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

void	startup_messages();
void	add_messages(int i);
int		check_phonenumber(std::string phoneNumber);

class Contacts {
	private:
		int			index;
		std::string	details[5];

	public:
		void	setDetails(int index) {
			this->index = index + 1;
			int	i = 0;
			while (i < 5) {
				add_messages(i);
				getline(std::cin, details[i]);
				if (details[i].empty()) {
					add_messages(5);
					continue;
				}
				else if (i == 3 && check_phonenumber(details[i])){
					add_messages(6);
					continue;
				}
				i++;
			}
		}

		void	getList() {
			std::string index = std::to_string(this->index);
			std::string field;
			std::cout << std::setw(10) << index;
			std::cout << '|';
			for (int i = 0; i <= 2; i++) {
				field = details[i];
				if (field.length() > 10) {
					field = field.substr(0, 10);
					field[9] = '.';
				}
				else if (field.length() < 10)
					std::cout << std::setw(10);
				std::cout << field;
				std::cout << '|';
			}
			std::cout << '\n';
		}

		void	getDetails() {
			std::cout << "\nFirst name: " << details[0] << '\n';
			std::cout << "Last name: " << details[1] << '\n';
			std::cout << "Nickname: " << details[2] << '\n';
			std::cout << "Phone number: " << details[3] << '\n';
			std::cout << "Darkest secret: " << details[4] << '\n';
		}
};

class PhoneBook {
	private:
		Contacts	contact[8];
		int			contact_amount;

	public:
		PhoneBook(int contact_amount) {
			this->contact_amount = contact_amount;
		}

		void	setDetails(int index){
			contact[index].setDetails(index);
		}


		void	getList(){
			std::cout << "    Index |first name| last name|  nickname|\n";
			for (int i = 0; i < contact_amount; i++)
				contact[i].getList();
		}

		void	getDetails(int index){
			contact[index - 1].getDetails();
		}


		int		getContact_amount(){
			return contact_amount;
		}
		void	setContact_amount(){
			if (contact_amount < 8)
				contact_amount++;
		}

};
