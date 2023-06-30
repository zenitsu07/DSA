class Item(object):
    def __init_(self,key,value):
        self.key = key
        self.value = value

class HashTable(object):

    def __init__(self,size):
        self.size = size
        self.table = [[] for _ in range(self.size)]#initialise table with size capacity

    #hash function maps the key to smaller hashing i.e. key module size capacity
    # 1st function
    def _hash_function(self,key):

        return key%self.size

    #assigning a  key to hashmap by wither updating its value or appending new key value pair to hash table
    def set(self, key, value):
        
        hash_index = self._hash_function(key)# Here key is passed to get specific smaller hashed key
        #loop through each item in hash_index table of indices to search for item.key

        for item in self.table[hash_index]:
            #if already exists then just update the value mapped to that key
            if(item.key == key):
                item.value = value
                return
        
        self.table[hash_index].append(Item(key,value))

    def get(self,key):
        hash_index = self._hash_function(key)#if hash 
        for item in self.table[hash_index]:
            if item.key == key:
                return item.value
        #else if not found key in table
        raise KeyError('Key not FOund')     
 

    def remove(self,key):
        hash_index = self._hash_function(key)
        for index,item in enumerate(self.table[hash_index]):
            if item.key == key:
                del self.table[hash_index][index]
                return 
        #The enumerate() function takes a collection (e.g. a tuple) and returns it as an enumerate object. The enumerate() function adds a counter as the key of the enumerate object.
        #x = ('apple', 'banana', 'cherry')  y = enumerate(x)  print(list(y)) ->  [(0, 'apple'), (1, 'banana'), (2, 'cherry')] SYNTAX - enumerate(iterable, start)
        raise KeyError('Key Not FOund')
