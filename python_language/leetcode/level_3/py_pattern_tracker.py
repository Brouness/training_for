def pattern_tracker(text: str) -> int:
    if not text:
        return 0
    base = "0123456789"
    i = 0
    ap = 0
    while (i < len(text) - 1):
        if text[i] == "9":
            i += 1
        elif text[i] in base and text[i + 1] == base[int(text[i]) + 1]:
            ap += 1
            i += 1
        else:
            i += 1
    return ap

print(pattern_tracker("123"))
print(pattern_tracker("12a34"))
print(pattern_tracker("987654321"))
print(pattern_tracker("01234567"))
print(pattern_tracker("abc"))
print(pattern_tracker("1a2b3c4"))
print(pattern_tracker("112233"))
