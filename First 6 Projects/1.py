a=[]
b=[]
c=[]

def group(grp,student_name):
    if student_name not in grp:
        grp.append(student_name)

print("Enter students in group A")
for student in input().split():
    group(a,student)

print("Enter students in group B")
for student in input().split():
    group(b,student)

print("Enter students in group C")
for student in input().split():
    group(c,student)

def first():
    both=[]
    for student in a:
        if student in b:
            both.append(student)
    return both

def second():
    either=[]
    for student in a:
        if student not in b:
            either.append(student)
    for student in b:
        if student not in a:
            either.append(student)
    return either

def third():
    all=[]
    y=[]
    for student in a:
            all.append(student)
    for student in b:
        if student not in a:
            all.append(student)
    for student in c:
        if student not in a and student not in b:
            all.append(student)

    for student in all:
        if student not in a and student not in b:
            y.append(student)
    return len(y)
def fourth():
    x=[]
    for student in a:
        if student not in b and student in c:
            x.append(student)
    return len(x)

print("List of students who play both cricket and badminton : ",first())
print("List of students who play either cricket or badminton but not both : ",second())
print("Number of students who play neither cricket nor badminton : ",third())
print("Number of students who play cricket and football but not badminton : ",fourth())