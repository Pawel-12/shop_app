#include "loginView.hpp"
#include "WelcomeView.hpp"

#include <iostream>
#include "../util/util.hpp"
#include "loggedMainView.hpp"

View* LoginView::display(session& session)
{
    auto& database = session.database;

    std::string email, password;
    while(true)
    {
        clearScreen();

        std::cout << "E-mail: ";
        std::cin >> email;

        std::cout << "Password: ";
        std::cin >> password;

        if (database.isUserExist(email)) //TODO: move to user session
        {
            auto user = database.getUser(email);
            if (user.password == password) {
                session.userEmail = email;
                return new LoggedMainView();
            }
        }else
            std::cout<<"Email or password doesnt match with database, do you want to try again? [Y/N]"<<std::endl;
            std::string choice;
            std::cin>>choice;
            if (choice == "N" || choice == "n"){
                return new WelcomeView();
            }
    }
}
