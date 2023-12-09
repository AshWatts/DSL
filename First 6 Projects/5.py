def bs():


#def sel_s():


#def is():


#def shell_s():





l = []
n = int(input("Enter number of Students : "))
for i in range(n):
    ele = float(input("Enter percentage : "))
    l.append(ele)

#quick_sort(l, 0, n - 1)

print("Displaying top 5 scores : ")
for i in range(5):
    print(l[n - i - 1])