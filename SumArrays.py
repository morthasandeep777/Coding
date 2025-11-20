def sum_array(arr):
    total = 0
    for num in arr:
        total += num
    return total

arr = [1, 2, 3, 4, 5]
result = sum_array(arr)

print("Sum of Array Elements:", result)
