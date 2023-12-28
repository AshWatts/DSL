def bs():
    for i in range(n-1):
        flag = False
        for j in range(n-i-1):
            if(l[j]>l[j+1]):
                (l[j],l[j+1])=(l[j+1],l[j])
                flag= True
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
    for i in range(1,n):
        temp=l[i]
        j=i-1
        while(j>=0 and temp<=l[j]):
            l[j+1]=l[j]
            j=j-1
        l[j+1]=temp
    print("Insertion Sort : ",l)

def shell_s():
    gap=n//2
    while(gap>0):
        i=gap
        while(i<n):
            j=i-gap
            while(j>=0):
                if(l[j+gap]>l[j]):
                    break
                else:
                    l[j],l[j+gap]=l[j+gap],l[j]
                j=j-gap
            i=i+1
        gap=gap//2

    print("Shell Sort : ",l)




l = []
n = int(input("Enter number of Students : "))
for i in range(n):
    ele = float(input("Enter percentage : "))
    l.append(ele)

bs()
sel_s()
ins()
shell_s()

print("Displaying top 5 scores : ")
for i in range(5):
    print(l[n - i - 1])