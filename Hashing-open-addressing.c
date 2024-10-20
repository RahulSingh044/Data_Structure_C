#include<stdio.h>
#define size 10

int HashTable[size];

//initializing the Hash Table
void initTable(){
    for(int i=0; i<size; i++){
        HashTable[i] = -1;
    }
}

//Hash Fucntion
int hash(int key) {
    return key%size;
}

//second Hash function for Double Hashing
int hash2(int key){
    return (7 - (key % 7));
}

//insert key into HashTable by Linear Probing
void linear_probing_insert(int key) {
    int index = hash(key);

    //linear Probing
    while(HashTable[index] != -1) {
        index = (index + 1) % size;
    }

    HashTable[index] = key;
}

//search key into HashTable
int linear_probing_search(int key){
    int index = hash(key);

    int startIndex = index;
    while(HashTable[index] != key){
        index = (index+1) % size;
        if(HashTable[index] == -1 || index == startIndex){
            return -1;
        }
    }

    return index;
}

//insert key into HashTable by Quadratic Probing
int quadratic_probing_insert(int key){
    int index = hash(key);
    int i = 1;

    //quadratic probing
    while(HashTable[index] != -1){
        if(i == size){
            printf("Hash Table is full");
        }
        index = (index+(i*i)) % size;
        i++;
    }

    return HashTable[index] = key;
}

// searching in HashTable using quadratic Probing
int quadratic_probing_search(int key){
    int index = hash(key);
    int i = 1;

    int startIndex = index;
    while(HashTable[index] != key){
        index = (index+i*i) % size;
        if(HashTable[index] == -1 || index == startIndex){
            return -1;
        }
        i++;
    }

    return index;
}

// insert key into HashTable using Double Hash
int double_hashing_insert(int key) {
    int index = hash(key);
    int index2 = hash2(key);
    int i = 0;

    while(HashTable[index] != -1){
        index = (index + i * index2 ) % size;
        i++;
    }

    return HashTable[index] = key;
}



//Function to display the hash table
void displayTable() {
    for (int i = 0; i < size; i++) {
        if (HashTable[i] == -1)
            printf("hashTable[%d] = Empty\n", i);
        else
            printf("hashTable[%d] = %d\n", i, HashTable[i]);
    }
}

int main() {
    initTable();

    double_hashing_insert(23);
    double_hashing_insert(43);
    double_hashing_insert(13);
    double_hashing_insert(27);
    double_hashing_insert(37);

    printf("Hash Table:\n");
    displayTable();

    int key = 43;
    int position = quadratic_probing_search(key);
    if (position != -1)
        printf("\nKey %d found at index %d\n", key, position);
    else
        printf("\nKey %d not found in hash table\n", key);

    return 0;
}
