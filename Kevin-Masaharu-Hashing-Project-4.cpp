// Name: Kevin Henderson
// CWID: 885395855
// Git repository Link:
// https://github.com/KevinHendersonCSUF/Kevin-Masaharu-Hashing-Project-4.git

// Name: Masaharu Saito
// CWID: 885148429
// Git repository Link:
// https://github.com/KevinHendersonCSUF/Kevin-Masaharu-Hashing-Project-4.git
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>

class Hash {
public:
  Hash() { table_ = table; }
  std::unordered_map<int, int> table{};
  void div_hash(std::string invalid, int M) {
    std::cout << "invalid input, key must be an integer!" << std::endl
              << std::endl;
  } // Function overload for invalid input
  void div_hash() {
    std::cout << "invalid input, please give a key and table size!" << std::endl
              << std::endl;
  } // function overload for null function argument
  void div_hash(int key, int M) {
    key_ = key;
    M_ = M;
    int index = key % M;
    if (table.count(index) != 0) {
      std::cout << "Failed to insert " << key << ". Collision occurred at "
                << index << ", using quadratic probing to find new index!"
                << std::endl;
      for (int i = 1; i <= M; i++) {
        std::cout << "i = " << i << std::endl;
        int new_index = (index + (i * i)) % M;
        if (table.count(new_index) == 0) {
          table.insert({new_index, key});
          std::cout << "After quadratic probing, " << key
                    << " is now stored at " << new_index << std::endl
                    << std::endl;
          break;
        }
      }
    } // QUADRATIC PROBING FOR COLLISIONS
    else {
      table.insert({index, key});
      std::cout << "inserted " << key << " at " << index << std::endl
                << std::endl;
    }
  }

  int mid_sqr_hash(int key, int M) {
    key_ = key;
    M_ = M;
    int index = 0;
    int squared_key = key * key;
    int amount_extracted = std::to_string(M - 1).length();
    std::string squared_key_string = std::to_string(squared_key);
    while (squared_key_string.length() > amount_extracted) {
      squared_key_string = squared_key_string.substr(1); // removes first number
      index = std::stoi(squared_key_string);
      if (squared_key_string.length() != amount_extracted) {
        squared_key_string =
            squared_key_string.substr(0, squared_key_string.size() - 1);
        index = std::stoi(squared_key_string);
      }
    }
    index = std::stoi(squared_key_string);

    if (table.count(index) != 0) {
      std::cout << "Failed to insert " << key << ". Collision occurred at "
                << index << ", using quadratic probing to find new index!"
                << std::endl;
      for (int i = 1; i <= M; i++) {
        std::cout << "i = " << i << std::endl;
        int new_index = (index + (i * i)) % M;
        if (table.count(new_index) == 0) {
          table.insert({new_index, key});
          std::cout << "After quadratic probing, " << key
                    << " is now stored at " << new_index << std::endl
                    << std::endl;
          break;
        }
      }

    } else { // QUADRATIC PROBING FOR COLLISIONS
      table.insert({index, key});
      std::cout << key << " inserted at " << index << std::endl << std::endl;
    }
    return 0;
  }
  int double_hash(int key, int M) {
    key_ = key;
    M_ = M;
    int index = 0;
    int h1 = key % M;
    int h2 = 1 + (key % 13);
    // palindrome index
    for (int i = 0; i < 6; i++) {
      index = (h1 + (i * h2));
      int reverse_index = 0;
      int palindrome_check = index;
      int num = 0;
      while (palindrome_check > 0) {
        num = palindrome_check % 10;
        reverse_index = reverse_index * 10 + num;
        palindrome_check = palindrome_check / 10;
      }
      if (index == reverse_index) {
        std::cout << index << " is a palindrome" << std::endl;
        break;
      } else {
        std::cout << index << " is not a palindrome" << std::endl;
      }

      if (i > 5) {
        index = reverse_index;
        break;
      }
    }
    std::cout << "inserted " << key << " at " << index << std::endl
              << std::endl;
    return 0;
  }

  void mult_hash(double key, double A, int M) {
    if (A < 0 || A > 1) {
      std::cout << "'A' must be between 0 and 1!" << std::endl << std::endl;
      return;
    }
    key_ = key;
    M_ = M;
    A_ = A;
    double key_calc = key * A;
    double fraction = std::fmod(key_calc, 1);
    int index = std::floor((M * fraction));
    if (table.count(index) != 0) {
      std::cout << "Failed to insert " << key << ". Collision occurred at "
                << index << ", using quadratic probing to find new index!"
                << std::endl;
      for (int i = 1; i <= M; i++) {
        std::cout << "i = " << i << std::endl;
        int new_index = (index + (i * i)) % M;
        if (table.count(new_index) == 0) {
          table.insert({new_index, key});
          std::cout << "After quadratic probing, " << key
                    << " is now stored at " << new_index << std::endl
                    << std::endl;
          break;
        }
      }
    } // QUADRATIC PROBING FOR COLLISIONS
    else {
      table.insert({index, key});
      std::cout << "inserted " << key << " at " << index << std::endl
                << std::endl;
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
hash_map.mid_sqr_hash(60, 100);//collision case
hash_map.mid_sqr_hash(7, 100);//smaller k value case
hash_map.mid_sqr_hash(90, 1000);//big m value case
hash_map.mid_sqr_hash(250, 100);//big k value & small m value case
hash_map.mid_sqr_hash(348, 10);//big k value; small m value
hash_map.mult_hash(12345, 0.357840, 100); // Normal insertion case
hash_map.mult_hash(14683, 3, 20); // A is greater than 1
hash_map.mult_hash(14683, -1 , 20); // A is less than 0
hash_map.mult_hash(60, 0.57, 25); // Normal insertion case
hash_map.mult_hash(45, 0.57, 25); // Normal insertion case
hash_map.double_hash(12345, 1000); // Normal insertion
hash_map.double_hash(123, 100); // Normal Insertion
hash_map.double_hash(12, 125); // K < M
hash_map.double_hash(45620, 125); // i>5 case
return 0;
}
