#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

// Function to split a string based on a delimiter
std::vector<std::string> splitString(const std::string& input, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream iss(input);
    std::string token;
    while (std::getline(iss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// int main() {
//     // std::ifstream inputFile("mudah-apartment-kl-selangor.csv"); // Replace "data.csv" with your CSV file name

//     // if (!inputFile) {
//     //     std::cerr << "Failed to open the file." << std::endl;
//     //     return 1;
//     // }

//     // std::string line;
//     // std::getline(inputFile, line); // Read the header line (optional)

//     // int i = 0;
//     // while (std::getline(inputFile, line)) {
//     //   std::vector<std::string> attributes = splitString(line, ','); // Split attributes based on comma delimiter
//     //   char targetChar = '\"';
//     //   std::string newItem = "";
//     //   bool cont = false;

//     //   for (int index = 0; index < attributes.size(); index++) {
//     //     std::string item = attributes[index];

//     //     int count = 0;

//     //     if (item != "") {
//     //       for (char c : item) {
//     //         if (c == targetChar && count == 0) {
//     //           cont = true;
//     //         }
//     //       }

//     //       int last = 0;
//     //       for (char c : item) {
//     //         if (c == targetChar && last == item.length()-1) {
//     //           cont = false;
//     //           newItem = newItem + ", " + item.substr(1, item.length()-2);
//     //           attributes[index] = newItem;
//     //           newItem = "";
//     //         }

//     //         last++;
//     //       }

//     //       if (cont) {
//     //         if (newItem != "") {
//     //           newItem += ", ";
//     //         }

//     //         newItem += item.substr(1, item.length());
//     //         attributes.erase(attributes.begin() + index);
//     //         index--;
//     //       }
//     //     }
//     //   }

//     //   std::string a1 = attributes[0];
//     //   std::string a2 = attributes[1];
//     //   std::string a3 = attributes[2];
//     //   std::string a4 = attributes[3];
//     //   std::string a5 = attributes[4];
//     //   std::string a6 = attributes[5];
//     //   std::string a7 = attributes[6];
//     //   std::string a8 = attributes[7];
//     //   std::string a9 = attributes[8];
//     //   std::string a10 = attributes[9];
//     //   std::string a11 = attributes[10];
//     //   std::string a12 = attributes[11];
//     //   std::string a13 = attributes[12];
//     //   std::string a14 = attributes[13];

//     //   // Do whatever you want with the attributes
//     //   std::cout << "1: " << a1 << std::endl;
//     //   std::cout << "2: " << a2 << std::endl;
//     //   std::cout << "3: " << a3 << std::endl;
//     //   std::cout << "4: " << a4 << std::endl;
//     //   std::cout << "5: " << a5 << std::endl;
//     //   std::cout << "6: " << a6 << std::endl;
//     //   std::cout << "7: " << a7 << std::endl;
//     //   std::cout << "8: " << a8 << std::endl;
//     //   std::cout << "9: " << a9 << std::endl;
//     //   std::cout << "10: " << a10 << std::endl;
//     //   std::cout << "11: " << a11 << std::endl;
//     //   std::cout << "12: " << a12 << std::endl;
//     //   std::cout << "13: " << a13 << std::endl;
//     //   std::cout << "14: " << a14 << std::endl;
//     //   std::cout << "-----------------------" << std::endl;

//       // for (std::string item : attributes) {
//       //   std::cout << item << " - ";
//       // }

//       // std::cout << std::endl << std::endl;


//     return 0;
// }