"""
Write a function that sorts a list of strings according to multiple criteria:
1.Primary sort: By string lenght (shortest first)
2.Secondary sort: ASCII order, except letters are compared case-insensitively
  (for strungs of same lenght)
3.Tertiary sort: By number of vowels (ascending, for same lenght and lexically equal)
4.Equal strings will appear in the same order as in the input list.

FORBIDEN FUNCTIONS: SORTED(), LIST.SORT()
"""

def helper(s1: str, s2: str):
    if len(s1) != len(s2):
        return len(s1) < len(s2)
    elif s1.lower() != s2.lower():
        return s1.lower() < s2.lower()
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
        return s1_v < s2_v
    return True

def cryptic_sorter(strings: list[str]) -> list[str]:
    i = 0
    while (i < len(strings)):
        j = i + 1
        while(j < len(strings)):
            if not helper(strings[i], strings[j]):
                tmp = strings[i]
                strings[i] = strings[j]
                strings[j] = tmp
            j += 1
        i += 1
    return strings
