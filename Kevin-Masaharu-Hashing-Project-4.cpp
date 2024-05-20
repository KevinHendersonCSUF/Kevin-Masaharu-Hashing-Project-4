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
#include <iomanip>

class Hash {
public:
Hash() {
    table_ = table;
} //UNCOMMENT IF MAIN FUNCTION ONLY USES ONE HASHMAP
std::unordered_map<int, int> table{};
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

int mid_sqr_hash(int key, int  M) {
    key_ = key;
    M_ = M;
    int squared_key = key * key;
    int index = (squared_key / 10) % 100; 
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
    } // QUADRATIC PROBING FOR COLLISIONS
    else {
      table.insert({index, key});
      std::cout << "Using r = 2, " << key << " inserted at " << index << std::endl;
    }
    return 0;
   }

int double_hash (int key, int M) {

    return 0;
}

int mult_hash(int key, double A) {

    return 0;
}

private: 
int key_ = 0;
int M_ = 0;
double A_ = 0.0;
std::unordered_map<int, int> table_{};
};

int main(){
Hash hash_map;
hash_map.div_hash(1234, 25);
hash_map.div_hash(59, 10); // collision case
hash_map.div_hash(69, 10); // double collision case
// try{
// hash_map.div_hash("String", 40);
// }
// catch (const char* msg) {
//      std::cerr << msg << std::endl;
//    }
hash_map.mid_sqr_hash(60, 100);
hash_map.mid_sqr_hash(75, 100);
return 0;
}
