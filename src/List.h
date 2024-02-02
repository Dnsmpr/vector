/*****************************************************************************************************/
/**
 * @file List.h
 * @brief Dynamic Array (Vector) Library
 * 
 * Provides an implementation of a dynamic array (vector), supporting operations such as initialization,
 * appending and popping elements, and querying properties of the vector.
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

/* Forward declaration of the vector structure. */
typedef struct vector vector;

/* Function pointer types for various operations on the vector. */
typedef void (*v_func)(vector*);       // Operations that return void
typedef void* (*vp_func)(vector*);     // Operations that return a void pointer
typedef void (*func)(void*, vector*);  // Operations that modify or interact with elements
typedef size_t (*s_func)(vector*);     // Operations that return a size_t
typedef bool (*b_func)(vector*);       // Operations that return a bool

/*****************************************************************************************************/
/* Internal structure containing vector's metadata and array of elements. */
typedef struct vector_impl {
    uint64_t size;                     // Current number of elements in the vector
    uint64_t capacity;                 // Maximum number of elements before resizing is needed
    void** item_list;                  // Array of pointers to the elements
    size_t bytes;                      // Size of each element in bytes
} vector_impl;

/* Main vector structure with operations defined as function pointers. */
typedef struct vector {
    vector_impl vec;                   // Internal vector implementation
    func append;                       // Append an element to the vector
    func front;                        // Add an element to the front of the vector
    v_func destroy;                    // Free the vector's resources
    v_func print;                      // Print the vector's contents
    s_func get_size;                   // Get the current number of elements
    b_func is_empty;                   // Check if the vector is empty
    vp_func pop;                       // Pop and return the last element
} vector;
/*****************************************************************************************************/

/* Vector API Function Declarations */

/*****************************************************************************************************/
/**
 * Initializes a new vector.
 * @param size Initial capacity of the vector.
 * @param bytes Size of each element in the vector.
 * @return Pointer to the newly created vector.
 */
vector* vec_init(uint64_t size, size_t bytes);

/**
 * Appends an item to the vector.
 * @param item Pointer to the item to be appended.
 * @param vec Pointer to the vector.
 */
void append(void* item, vector* vec);

/**
 * Adds an item to the front of the vector.
 * @param item Pointer to the item to be added to the front.
 * @param vec Pointer to the vector.
 */
void front(void* item, vector* vec);

/**
 * Prints the contents of the vector.
 * @param vec Pointer to the vector.
 */
void print(vector* vec);

/**
 * Returns the current number of elements in the vector.
 * @param vec Pointer to the vector.
 * @return Number of elements.
 */
size_t get_size(vector* vec);

/**
 * Checks if the vector is empty.
 * @param vec Pointer to the vector.
 * @return True if empty, false otherwise.
 */
bool is_empty(vector* vec);

/**
 * Pops and returns the last element of the vector.
 * @param vec Pointer to the vector.
 * @return Pointer to the popped element.
 */
void* pop(vector* vec);

/**
 * Destroys the vector and frees its resources.
 * @param vec Pointer to the vector to be destroyed.
 */
void destroy(vector* vec);

/**
 * Add item at a specified index.
 * @param vec Pointer to the vector to be destroyed.
 * @param index Position to insert item.
 * @param item Pointer to the item to be added at position index.
 */
void add_at_index(vector* vec, size_t index, void* item);
/*****************************************************************************************************/

#endif // LIST_H
