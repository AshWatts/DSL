def quick_sort():
    print("hi")
    


l=[]
n=int(input(("Enter number of Students : ")))
for i in range(n):
    ele=float(input("Enter percentage : "))
    l.append(ele)

quick_sort()

print("Displaying top 5 scores : ")
for i in range(5):
    print(l[n-i-1])