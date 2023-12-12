#5


def bs():
    for i in range(n):
        flag=False
        for j in range(n-i-1):
            if(l[j]>l[j+1]):
                (l[j],l[j+1])=(l[j+1],l[j])
                flag=True
        if(flag==False):
            break
    print("Binary Sort : ",l)


def sel_s():
    for i in range(n):
        min=i
        for j in range(i+1,n):
            if(l[min]>l[j]):
                min=j
        l[i],l[min]=l[min],l[i]
    print("Selection Sort : ",l)


def ins():
    

l = []
n = int(input("Enter number of Students : "))
for i in range(n):
    ele = float(input("Enter percentage : "))
    l.append(ele)

bs()
sel_s()
ins()

print("Displaying top 5 scores : ")
for i in range(5):
    print(l[n - i - 1])