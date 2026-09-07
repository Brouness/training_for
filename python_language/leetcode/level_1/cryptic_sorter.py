def should_come_before(s1: str, s2: str) -> bool:
    if len(s1) != len(s2):
        return len(s1) > len(s2)
    elif s1.lower() != s2.lower():
        return s1.lower() > s2.lower()
    vowels = "aeiou"
    s1_v = 0
    s2_v = 0
    for char in s1:
        if char in vowels:
            s1_v += 1
    for char in s2:
        if char in vowels:
            s2_v += 1
    if s1_v != s2_v:
        return s1_v > s2_v
    return False

def cryptic_sorter(strings: list[str]) -> list[str]:
    lenght = len(strings)
    i = 0
    while(i < lenght):
        j = i + 1
        while (j < lenght):
            if should_come_before(strings[i], strings[j]):
                tmp = strings[i]
                strings[i] = strings[j]
                strings[j] = tmp
            j += 1
        i += 1
    return strings

print(cryptic_sorter(["apple","cat","banana","dog","elephant"]))