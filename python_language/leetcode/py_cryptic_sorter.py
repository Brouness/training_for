"""
Write a function that sorts a list of strings according to multiple criteria:
1.Primary sort: By string lenght (shortest first)
2.Secondary sort: ASCII order, except letters are compared case-insensitively
  (for strungs of same lenght)
3.Tertiary sort: By number of vowels (ascending, for same lenght and lexically equal)
4.Equal strings will appear in the same order as in the input list.

FORBIDEN FUNCTIONS: SORTED(), LIST.SORT()
"""

def cryptic_sorter(strings: list[str]) -> list[str]:
    sorted_list = []
    for s in strings:
        little = s
        for j in strings:
            if (len(j) < len(s)):
                little = j
        sorted_list.append(little)
        strings.remove(little)
    if len(strings) == 1:
        sorted_list.append(strings[0])
    return new_list

cryptic_sorter(["youness", "hamid", "salah"])
