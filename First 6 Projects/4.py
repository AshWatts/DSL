a = []
n = int(input("Enter number of students : "))
for i in range(n):
    ele = int(input("Enter the Roll Number : "))
    a.append(ele)
z = int(input("Enter the roll number to be searched : "))


def ls():
    flag = False
    for i in range(n):
        if i == z:
            print("Position of Given Student : ", i)
            flag = True
            break
    if flag == False:
        print("Given Roll Number is missing!")


def bs():
    flag = False
    a.sort()
    low = 0
    high = n - 1
    mid = 0

    while low <= high:
        mid = (low + high) // 2
        if z == a[mid]:
            print("Position of given student ", mid + 1)
            flag == True
            break
        elif z < a[mid]:
            high = mid - 1
        else:
            low = mid + 1

    if flag == False:
        print("Given Roll Number is missing!")


def ss():
    last = a[n - 1]
    a[n - 1] = z
    i = 0
    while a[i] != z:
        i += 1

    a[n - 1] = last

    if (i < n - 1) or (a[n - 1] == z):
        print("Position of Given Student : ", i + 1)
    else:
        print("Given Roll Number is missing!")


def fs():
    m2 = 0
    m1 = 1
    m = m1 + m2
    while m < n:
        m2 = m1
        m1 = m
        m = m1 + m2

    offset = 0

    while m > 1:
        i = min(offset + m2, n - 1)
        if a[i] < z:
            m = m1
            m1 = m2
            m2 = m - m1
            offset = i
        elif a[i] > z:
            m = m2
            m1 = m1 - m2
            m2 = m - m1
        else:
            return i

    if m1 and a[n - 1] == z:
        return n - 1

    return -1


print("""Searching Types : 
1. Linear Search
2. Binary Search
3. Sentinel Search
4. Fibonacci Search
""")
m = int(input("Enter your choice : "))

if m == 1:
    ls()

elif m == 2:
    bs()

elif m == 3:
    ss()

elif m == 4:
    x = fs()
    if x>=0:
        print("Position of Given Student : ",x+1)
    else:
        print("Given Roll Number is missing!")

else:
    print("Invalid Choice")