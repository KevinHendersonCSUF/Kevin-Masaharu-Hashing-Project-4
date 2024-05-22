// Name: Kevin Henderson
// CWID: 885395855
// Git repository Link:
// https://github.com/KevinHendersonCSUF/Kevin-Masaharu-Hashing-Project-4.git

// Name: Masaharu Saito
// CWID: 885148429
// Git repository Link:
// https://github.com/KevinHendersonCSUF/Kevin-Masaharu-Hashing-Project-4.git
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>

class Hash {
public:
Hash() {
    table_ = table;
} //UNCOMMENT IF MAIN FUNCTION ONLY USES ONE HASHMAP
std::unordered_map<int, int> table{};
void div_hash(std::string invalid, int M) {
  std::cout << "invalid input, key must be an integer!" << std::endl;
}
void div_hash() {
  std::cout << "invalid input, please give a key and table size!" << std::endl;
}
void div_hash(int key, int M) {
    // std::unordered_map<int, int> table{}; // DELETE IF MAIN FUNCTION ONLY USES ONE HASHMAP
    key_ = key;
    M_ = M;
    int index = key % M;
    if(table.count(index) != 0) {
        std::cout << "Collision occurred at " << index << ", using quadratic probing to find new index!" << std::endl;
        for(int i = 1; i <= M; i++) {
            std::cout << "i = " << i << std::endl;
            int new_index = (index + (i * i)) % M;
            if(table.count(new_index) == 0) {
                table.insert({new_index, key});
                std::cout << "After quadratic probing, " << key << " is now stored at " << new_index << std::endl;
                break;
            }
        }
    }// QUADRATIC PROBING FOR COLLISIONS
    else {
    table.insert({index, key});
    std::cout << "inserted " << key << " at " << index << std::endl;
    }
    // if () {
    //   throw "Invalid key, key must be an integer!";
    // }
}

int mid_sqr_hash(int key, int M) {
    key_ = key;
    M_ = M;
    int index = 0;
    int squared_key = key * key;
    //std::cout << "Squared Key = " << squared_key << std::endl;
    int amount_extracted = std::to_string(M - 1).length();
    std::string squared_key_string = std::to_string(squared_key);
    //std::cout << "Squared key length = " << squared_key_string.length()
              //<< std::endl;
    while (squared_key_string.length() > amount_extracted) {
      squared_key_string = squared_key_string.substr(1);//removes first number
      index = std::stoi(squared_key_string);
      //std::cout << "Result string = " << squared_key_string << std::endl;
     // std::cout << "squared_key_string length = " << squared_key_string.length() << std::endl;
      if (squared_key_string.length() != amount_extracted) {
        squared_key_string = squared_key_string.substr(0, squared_key_string.size() - 1);
        //std::cout << "Result string2 = " << squared_key_string << std::endl;

        index = std::stoi(squared_key_string);
        }
      }
    index = std::stoi(squared_key_string);
  
    if (table.count(index) != 0) {
      std::cout << "Collision occurred at " << index
                << ", using quadratic probing to find new index!" << std::endl;
      for (int i = 1; i <= M; i++) {
        std::cout << "i = " << i << std::endl;
        int new_index = (index + (i * i)) % M;
        if (table.count(new_index) == 0) {
          table.insert({new_index, key});
          std::cout << "After quadratic probing, " << key
                    << " is now stored at " << new_index << std::endl;
          break;
        }
      }
      
    } else { // QUADRATIC PROBING FOR COLLISIONS
      table.insert({index, key});
      std::cout << key << " inserted at " << index
                << std::endl;
    }
    return 0;
  }
int double_hash (int key, int M) {

    return 0;
}

void mult_hash(double key, double A, int M) {
  if(A < 0 || A > 1) {
    std::cout << "'A' must be between 0 and 1!" << std::endl;
    return;
  }
    key_ = key;
    M_ = M;
    A_ = A;
    double key_calc = key * A;
    double fraction = std::fmod(key_calc, 1);
    int index = std::floor((M*fraction));
        if(table.count(index) != 0) {
        std::cout << "Collision occurred at " << index << ", using quadratic probing to find new index!" << std::endl;
        for(int i = 1; i <= M; i++) {
            std::cout << "i = " << i << std::endl;
            int new_index = (index + (i * i)) % M;
            if(table.count(new_index) == 0) {
                table.insert({new_index, key});
                std::cout << "After quadratic probing, " << key << " is now stored at " << new_index << std::endl;
                break;
            }
        }
    }// QUADRATIC PROBING FOR COLLISIONS
    else {
    table.insert({index, key});
    std::cout << "inserted " << key << " at " << index << std::endl;
    }
}

private: 
int key_ = 0;
int M_ = 0;
double A_ = 0.0;
std::unordered_map<int, int> table_{};
};

int main(){
Hash hash_map;
hash_map.div_hash(1234, 25); //normal insertion case
hash_map.div_hash(59, 10); // collision case
hash_map.div_hash(69, 10); // double collision case
hash_map.div_hash(); // null case
hash_map.div_hash("This shouldnt work", 25); //wrong argument case
hash_map.mid_sqr_hash(60, 100);//normal
hash_map.mid_sqr_hash(7, 100);//smaller k value
hash_map.mid_sqr_hash(90, 1000);//big m value
hash_map.mid_sqr_hash(250, 100);//big k value; small m value
hash_map.mid_sqr_hash(348, 10);//big k value; small m value
hash_map.mult_hash(12345, 0.357840, 100); // Normal insertion case
hash_map.mult_hash(14683, 3, 20); // A is greater than 1
hash_map.mult_hash(14683, -1 , 20); // A is less than 0
hash_map.mult_hash(60, 0.57, 25); // Normal insertion case
hash_map.mult_hash(45, 0.57, 25); // Normal insertion case
return 0;
}
