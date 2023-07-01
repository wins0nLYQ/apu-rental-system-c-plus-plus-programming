#ifndef ASIA_PACIFIC_HOME_H
#define ASIA_PACIFIC_HOME_H

/**
 * FILENAME: Asia_Pacific_Home.h
*/

#include <string>
#include "User.h"

class Asia_Pacific_Home {

public:
    User user;
    Asia_Pacific_Home();
    void loginPage();
    void homePage();
    void admin_HomePage();
    void admin_ManageManagerPage();
    // void admin_AddNewManagerPage();
    void admin_ModifyManagerStatusPage();
    void admin_ViewTenantInfoPage();
};

#endif