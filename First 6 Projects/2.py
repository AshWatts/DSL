def long(text):
    words = text.split()
    longest = words[0]
    for i in words:
        if len(i) > len(longest):
            longest = i
    return longest


def freq(x, text):
    count = 0
    for i in text:
        if i == x:
            count += 1
    return count


def pal(text):
    for i in range(len(text) // 2):
        if text[i] != text[-i - 1]:
            return False
    return True


def subs(subt, text):
    index = -1
    for i in range(len(text)):
        if text[i:i + len(subt)] == subt:
            index = i
            break
    return index


def occ(text):
    word_counts = {}
    for i in text.split():
        if i in word_counts:
            word_counts[i] += 1
        else:
            word_counts[i] = 1
    return word_counts


input_text = input("Enter your String : ")

print("Longest word : ", long(input_text))

input_char = input("Enter character whose frequency is to be calculated : ")
print("Frequency : ", freq(input_char, input_text))

print("Palindrome : ", pal(input_text))

input_subt = input("Enter the Substring : ")
print("Index of Substring : ", subs(input_subt, input_text))

print("Occurences of each word : ", occ(input_text))
