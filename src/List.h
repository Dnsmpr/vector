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

/* Vector API Function Declarations */

/*****************************************************************************************************/
/**
 * Initializes and returns a new vector with a specified capacity and element size.
 *
 * @param size The initial capacity of the vector.
 * @param bytes The size of each element in the vector.
 * @return A pointer to the newly created vector.
 */
vector init(uint64_t size, size_t bytes);

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
size_t getSize(vector vec);

/**
 * Checks if the vector is empty.
 *
 * @param vec A pointer to the vector.
 * @return True if the vector is empty, otherwise false.
 */
bool isEmpty(vector vec);

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
void addAtIndex(vector vec, size_t index, void* item);

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
void deleteFront(vector vec);

/**
 * Deletes the item at the end of the vector.
 *
 * @param vec A pointer to the vector.
 */
void deleteBack(vector vec);

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
 * @return A deep cloned vector instance of vec.
 */
vector clone(vector vec);

/**
 * Returns the capacity.
 *
 * @param vec A pointer to the vector.
 * @return The current capacity for the vector.
 */
size_t getCapacity(vector vec);

/**
 * Reverses the elements in a vector.
 *
 * @param vec A pointer to the vector.
 */
void reverse(vector vec);

/**
 * Determines whether the vector contains a specific pointer.
 *
 * This function searches the vector for an element that matches the provided pointer
 * and returns true if the pointer is found, indicating the presence of the element.
 *
 * @param vec A pointer to the vector.
 * @param item The pointer whose presence in the vector is being checked.
 * @return True if the item pointer is found in the vector; otherwise, false.
 */
bool contains(vector vec, void* item);
/*****************************************************************************************************/

/**
 * A function pointer type for comparing two elements.
 *
 * This typedef defines a pointer to a function that compares two elements. The function
 * pointed to by this type must take two void pointers as arguments, representing the two
 * elements to be compared. It returns an integer to indicate the result of the comparison.
 *
 * The function should return:
 * - A negative integer if the first element is considered less than the second element.
 * - Zero if the first element is considered equal to the second element.
 * - A positive integer if the first element is considered greater than the second element.
 *
 * This comparison function is used to impose an ordering on the elements being sorted or
 * manipulated. It allows generic sorting and manipulation algorithms to work with any data
 * type by abstracting the comparison logic into this function.
 */
typedef int (*compare)(void*, void*);

/**
 * Sorts the elements of the vector in the specified range using the quicksort algorithm.
 *
 * @param vec     A pointer to the vector to be sorted.
 * @param compare A pointer to a comparison function that takes two void pointers as arguments
 *                and returns an integer less than, equal to, or greater than zero if the first argument
 *                is considered to be respectively less than, equal to, or greater than the second.
 * @param low     The starting index of the segment of the vector to be sorted. This index should be within
 *                the bounds of the vector.
 * @param high    The ending index of the segment of the vector to be sorted. This index should be within
 *                the bounds of the vector and not less than 'low'.
 */
void sort(vector vec, compare c, int low, int high);

/**
 * Prints the elements of an integer vector.
 *
 * This function iterates through the vector, assuming that each element is an integer, and
 * prints each integer to the standard output. Each element is printed using the "%d" format
 * specifier, suitable for integers. The elements are printed in the order they appear in the
 * vector, each followed by a newline character for clear separation.
 *
 * @param vec A pointer to the vector whose elements are to be printed.
 *
 * Note: This function does not perform any type checking on the elements of the vector. It
 *       blindly treats each element as an integer. Therefore, it is the caller's responsibility
 *       to ensure that the vector indeed contains only integers before calling this function.
 */
void printi(vector vec);

/**
 * Returns a pointer to item at specified index.
 *
 * This function returns a void* to an item at the given index.
 * If the index exceeds the size of the vector, a pointer to the last element is supplied.
 * @param vec A pointer to the vector.
 * @param index The position of the element.
 */
void* getItemAtIndex(vector vec, size_t index);

#endif // LIST_H
