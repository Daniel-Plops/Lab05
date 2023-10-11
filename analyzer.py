import stringdata
import time


# Checks each individual element in index order
def linear_search(container, search):
    for i in range(len(container)):
        if container[i] == search:
            return i
    return -1


# Uses binary search emthod to return index of search element
def binary_search(container, search):
    l = len(container)
    mid = l // 2
    low = 0
    high = l-1

    # While loop that changes low and high to change the bounds of the search until they reach the search element
    while low <= high:
        if container[mid] < search:
            low = mid + 1
        elif container[mid] > search:
            high = mid - 1
        else:
            return mid
        mid = (high - low) // 2 + low
    return -1


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    dataset = stringdata.get_data()

    # Store all times and print them with index and search type
    t1 = time.time()
    linear_search(dataset, "not_here")
    t2 = time.time()-t1
    t3 = time.time()
    test = binary_search(dataset, "not_here")
    t4 = time.time()-t3
    print("Index: " + str(test))
    print(f'Time for \'not_here\'\n Linear: {t2} sec \n Binary: {t4} sec \n')

    t5 = time.time()
    linear_search(dataset, "mzzzz")
    t6 = time.time()-t5
    t7 = time.time()
    test = binary_search(dataset, "mzzzz")
    t8 = time.time()-t7
    print("Index: " + str(test))
    print(f'Time for \'mzzzz\'\n Linear: {t6} sec \n Binary: {t8} sec \n')

    t9 = time.time()
    linear_search(dataset, "aaaaa")
    t10 = time.time()-t9
    t11 = time.time()
    test = binary_search(dataset, "aaaaa")
    t12 = time.time()-t11
    print("Index: " + str(test))
    print(f'Time for \'aaaaa\'\n Linear: {t10} sec \n Binary: {t12} sec \n')
