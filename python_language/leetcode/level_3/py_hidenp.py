def hidenp(small: str, big: str) -> bool:
    i = 0
    j = 0
    if not small:
        return True
    while i < len(big) and j < len(small):
        if (big[i] == small[j]):
            j += 1
        i += 1
    return j == len(small)

print(hidenp("abc", "a1b2c3"))
print(hidenp("ace", "abcde"))
print(hidenp("aec", "abcde"))
print(hidenp("", "abc"))
print(hidenp("abc", "ab"))
print(hidenp("aaaa", "aaa"))
print(hidenp("sing","subsequence testing"))