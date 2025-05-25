from typing import List
import sys

class Record:
    def __init__(self, key=None, number_of_offsets=None):
        self.key = key
        self.number_of_offsets = number_of_offsets
    def __str__(self):
        return str(self.key)
    
class ComputedChainingHashTableSafe:
    def __init__(self, size):
        self.size = size
        self.table: List[Record] = [Record() for _ in range(size)]
        self.accesses = 0
    
    def _increase_access(self, custom_increase=None):
        self.accesses = self.accesses + 1 if custom_increase == None else self.accesses + custom_increase

    def _hash(self, key):
        return key % self.size

    def _incrementing_function(self, key):
        return int(key / self.size) % self.size

    def _probe(self, key, current_position, incrementing_function):
        return (current_position + incrementing_function(key)) % self.size

    def _get_target_position(self, h):
        attempts = 0
        next_position = h
        base_position = h # Value from where the NOF is none
        self._increase_access()
        number_of_offsets = 0
        while (self.table[next_position].number_of_offsets is not None):
            print(f"Position {next_position} is being used by key {self.table[next_position]}")
            if (attempts == self.size): # The table is full
                return -1, -1, -1
            nof = self.table[h].number_of_offsets
            inc = self._incrementing_function(self.table[next_position].key)
            next_position = (next_position + inc * nof) % self.size
            attempts += 1
            self._increase_access()
            
        base_position = next_position
        while (self.table[next_position].key is not None): # Search empty position to insert the key
            # next_position = (next_position + self._incrementing_function(self.table[base_position].key)) % self.size
            if (attempts == self.size): # The table is full
                return -1, -1, -1
            next_position = self._probe(self.table[base_position].key, next_position, self._incrementing_function)
            number_of_offsets += 1
            attempts += 1
            self._increase_access()
        return next_position, base_position, number_of_offsets

    def _move(self, record: Record, h):
        attempts = 0
        while (record.number_of_offsets is not None):
            attempts += 1
            if (attempts == self.size): # The table is full
                return self.accesses
            nof = record.number_of_offsets
            inc = self._incrementing_function(record.key)
            successor_position = (h + inc * nof) % self.size
            self._increase_access()
            aux = Record(self.table[successor_position].key, self.table[successor_position].number_of_offsets)
            self.table[successor_position].key = record.key
            self.table[successor_position].number_of_offsets = None
            print(f"Key: {record.key}; Target position: {successor_position}; Nof marked as None")
            record = aux
            h = successor_position
            
        
        target_position, base_position, nof = self._get_target_position(h)
        if (target_position != -1): # The insertion is possible
            print(f"Key: {record.key}; Target position: {target_position}; Nof marked for {self.table[base_position].key}: {nof}")
            self.table[target_position].key = record.key
            self.table[base_position].number_of_offsets = nof
        else:
            print("Key not inserted.")
        return self.accesses

    def insert(self, key):
        self.accesses = 0
        h = self._hash(key)

        if (self.table[h].key is None):
            print(f"Key: {key} inserted in position {h} with no collisions.")
            self.table[h].key = key
            return 1
        
        if (self.table[h].key == key):
            print(f"The key {key} already exists in the table!")
            return 1
            
        # print(f"Key: {key}; Collision with {self.table[h].key}")
        # if (self.table[h].key is not None): # Collision!
        if (self._hash(self.table[h].key) == self._hash(key)): # check if it's the home address
            target_position, base_position, nof = self._get_target_position(h)
            print(f"Key: {key}; Target position: {target_position}; Nof marked for {self.table[base_position].key}: {nof}")
            if (target_position != -1): # The insertion is possible
                self.table[target_position].key = key
                self.table[base_position].number_of_offsets = nof
            else:
                print("Key not inserted.")
        else:
            aux = self.table[h]
            self.table[h] = Record(key, None)
            print(f"Insert {key} in home address; Key: {aux} not in home address; reinserting")
            self._move(aux, h)
            
        return self.accesses # Para fins pedagogicos
    
keys = [int(x) for x in sys.argv[1].split(',')]
# [27, 18, 29, 28, 39, 13, 16, 38, 53]
hash_table = ComputedChainingHashTableSafe(11)
for key in keys:
    hash_table.insert(key)