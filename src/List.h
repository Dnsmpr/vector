/*****************************************************************************************************/
/**
 * @file List.h
 * @brief Dynamic Array (Vector) Library
 *
 * Provides an implementation of a dynamic array (vector), supporting operations such as
 * initialization, appending, prepending, popping elements, and querying properties of the vector.
 * Additional functionalities include adding, replacing, and deleting elements at specific
 * positions, as well as capacity management to efficiently utilize memory.
 */
/*****************************************************************************************************/

#ifndef LIST_H
#define LIST_H

/*****************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
/*****************************************************************************************************/

/* Opaque pointer to a vector instance, hiding the implementation details. */
typedef struct vector_impl* vector;

/*****************************************************************************************************/
/* Definition of the internal structure for the vector, including its size, capacity,
 * an array of pointers to elements, and the size of each element. */
typedef struct vector_impl {
    uint64_t size;        // Current number of elements in the vector
    uint64_t capacity;    // Maximum number of elements before resizing is needed
    void** item_list;     // Array of pointers to the elements
    size_t bytes;         // Size of each element in bytes
} vector_impl;

/*****************************************************************************************************/

/* Vector API Function Declarations */

/*****************************************************************************************************/
/**
 * Initializes and returns a new vector with a specified capacity and element size.
 *
 * @param size The initial capacity of the vector.
 * @param bytes The size of each element in the vector.
 * @return A pointer to the newly created vector.
 */
vector vec_init(uint64_t size, size_t bytes);

/**
 * Appends an item to the end of the vector.
 *
 * @param vec A pointer to the vector.
 * @param item A pointer to the item to be appended.
 */
void append(vector vec, void* item);

/**
 * Inserts an item at the front of the vector.
 *
 * @param vec A pointer to the vector.
 * @param item A pointer to the item to be added to the front.
 */
void front(vector vec, void* item);

/**
 * Prints the contents of the vector.
 *
 * @param vec A pointer to the vector.
 */
void print(vector vec);

/**
 * Returns the current number of elements in the vector.
 *
 * @param vec A pointer to the vector.
 * @return The number of elements in the vector.
 */
size_t get_size(vector vec);

/**
 * Checks if the vector is empty.
 *
 * @param vec A pointer to the vector.
 * @return True if the vector is empty, otherwise false.
 */
bool is_empty(vector vec);

/**
 * Removes and returns the last element of the vector.
 *
 * @param vec A pointer to the vector.
 * @return A pointer to the popped element.
 */
void* pop(vector vec);

/**
 * Frees the vector and its resources.
 *
 * @param vec A pointer to the vector to be destroyed.
 */
void destroy(vector vec);

/**
 * Inserts an item at a specified index within the vector.
 *
 * @param vec A pointer to the vector.
 * @param index The position at which to insert the item.
 * @param item A pointer to the item to be added.
 */
void add_at_index(vector vec, size_t index, void* item);

/**
 * Replaces an item at a specified index within the vector.
 *
 * @param vec A pointer to the vector.
 * @param index The index of the item to be replaced.
 * @param item A pointer to the new item to be placed at the specified index.
 */
void replace(vector vec, size_t index, void* item);

/**
 * Deletes the item at the front of the vector.
 *
 * @param vec A pointer to the vector.
 */
void deletef(vector vec);

/**
 * Deletes the item at the end of the vector.
 *
 * @param vec A pointer to the vector.
 */
void deleteb(vector vec);

/**
 * Reduces the capacity of the vector to match its current size, minimizing memory usage.
 *
 * @param vec A pointer to the vector.
 */
void shrink(vector vec);

/**
 * Returns a deep clone of the vector.
 *
 * @param vec A pointer to the vector.
 */
vector clone(vector vec);
/*****************************************************************************************************/

#endif // LIST_H
