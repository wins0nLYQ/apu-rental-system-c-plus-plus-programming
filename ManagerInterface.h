#include<string>
#include<iostream>
#include "Manager.h"

class ManagerInterface
{
private:
  Manager manager;

public:
  ManagerInterface(Manager manager)
  {
    this->manager = manager;
  }
  void managerHomePage()
  {
    std::cout << "-------------------------------------------------------------" << endl;
    std::cout << "-------------------------------------------------------------" << endl;
    std::cout << "                           MANAGER                           " << endl;
    std::cout << "-------------------------------------------------------------" << endl;
    std::cout << "WELCOME BACK! " << manager.getName() << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Please select an option (1-3):" << std::endl;
    std::cout << "1. Display All Registered Tenant' Details" << std::endl;
    std::cout << "2. Favorite Property List" << std::endl;
    std::cout << "3. View Property Information" << std::endl;
    std::cout << "4. Logout" << std::endl;
    std::cout << ">> ";
  }

  // Get current manager
  Manager getCurrentManager()
  {
    return this->manager;
  }
};