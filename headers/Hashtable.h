/*#include <iostream>
#include <unordered_set> // Hash set
#include <set>		// Tree set
#include <functional>
#include <sstream>
#include <string>
#include <vector>
#include "Nurse.h"
#include "Patient.h"
#include "Hospital.h"
using namespace std;

struct Hash_Table_Entry{
    Nurse key;
    Patient* value;
    Hash_Table_Entry(Nurse key, Patient * value){
        this->key = key;
        this-> value = value;
    }
};

class Hash_Table{
private:
    //Hash_Table_Entry **;
	int HASH_SIZE;	// Size of my hash table
    vector<set<Patient>> hash_table;	    // HASH TABLE with chaining!
	void hash_function(Nurse key){
        return 
    }

public:

	Hash_Table(int Hash_size) {
        hash_table.resize(Hash_size);
        /*HASH_SIZE = Hash_size;
        height = new Hash_Table_Entry*[HASH_SIZE];
        for(int i = 0; i < HASH_SIZE; i++){
            height[i] = NULL;
        }
	}


	void insert(Patient value) {
		int index = 
	}


	void erase(const T & item) {
		int indx = hashfunc(item) % HASH_SIZE;
		hash_table[indx].erase(item);
	}

	bool find(const T & item) {
		// FIXME: Complete the implementation for find
	
		return false;
	}

    void find_patient(Nurse key){

    }

       Declare function SearchKey(int k)
      int hash_v = HashFunc(k)
      bool flag = false
      HashTableEntry* en = ht[hash_v]
      if (en != NULL)
         while (en != NULL)
            if (en->k == k)
               flag = true
            if (flag)
               Print “Element found at key”
               Print en->v
            en = en->n
      if (!flag)
         Print “No Element found at key”
};*/
