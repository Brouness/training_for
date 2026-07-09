"""
Write a function that sorts a list of strings according to multiple criteria:
1. Primary sort: By string length (shortest first)
2. Secondary sort: ASCII order, except letters are compared case-insensitively
   (for strings of same length)
3. Tertiary sort: By number of vowels (ascending, for same length and lexically equal)
4. Equal strings will appear in the same order as in the input list.

Forbidden functions: sorted(), list.sort()

Function signature

def cryptic_sorter(strings: list[str]) -> list[str]:
    """

def should_come_before(a, b) -> bool:
    if len(a) != len(b):
        return len(a) < len(b)
    elif a.lower() != b.lower():
        return a.lower() < b.lower()
    s = "aeiou"
    x = 0
    y = 0

    for i in a:
        if i in s:
            x = x + 1
    for i in b:
        if i in s:
            y = y + 1
    if x == y:
        return True
    return x - y


def cryptic_sorter(strings: list[str]) -> list[str]:
    lenght = len(strings)
    i = 0
    while (i < lenght):
        j = i + 1
        while (j < lenght):
            if not should_come_before(strings[i], strings[j]):
                tmp = strings[i]
                strings[i] = strings[j]
                strings[j] = tmp
            j += 1
        i += 1
    return strings


print(cryptic_sorter(["apple","cat","banana","dog","elephant"]))
print(cryptic_sorter(["aaa","bbb","AAA","BBB"]))
print(cryptic_sorter([""]))
