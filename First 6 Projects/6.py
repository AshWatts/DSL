def partition(l, low, high):
    pivot = l[high]
    i = low - 1

    for j in range(low, high):
        if (l[j] <= pivot):
            i += 1
            (l[i], l[j]) = (l[j], l[i])
    (l[i + 1], l[high]) = (l[high], l[i + 1])
    return i + 1


def quick_sort(l, low, high):
    if low < high:
        p = partition(l, low, high)
        quick_sort(l, low, p - 1)
        quick_sort(l, low + 1, high)


l = []
n = int(input("Enter number of Students : "))
for i in range(n):
    ele = float(input("Enter percentage : "))
    l.append(ele)

quick_sort(l, 0, n - 1)

print("Sorted List : ",l)

print("Displaying top 5 scores : ")
for i in range(5):
    print(l[n - i - 1])