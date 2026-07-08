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
def _should_come_before(a: str, b: str) -> bool:
    """Return True if string a should be placed strictly before string b."""
    # 1. Primary: length
    if len(a) != len(b):
        return len(a) < len(b)

    # 2. Secondary: case-insensitive ASCII order
    a_lower = a.lower()
    b_lower = b.lower()
    if a_lower != b_lower:
        return a_lower < b_lower

    # 3. Tertiary: vowel count
    vowels = set("aeiouAEIOU")
    a_vowels = sum(1 for ch in a if ch in vowels)
    b_vowels = sum(1 for ch in b if ch in vowels)
    if a_vowels != b_vowels:
        return a_vowels < b_vowels

    # 4. Fully equal by all criteria -> not strictly before (keep original order)
    return False


def cryptic_sorter(strings: list[str]) -> list[str]:
    result = list(strings)  # copy, so we don't mutate the input

    # Insertion sort
    for i in range(1, len(result)):
        current = result[i]
        j = i - 1
        # Shift elements right while they should come AFTER `current`
        while j >= 0 and _should_come_before(current, result[j]):
            result[j + 1] = result[j]
            j -= 1
        result[j + 1] = current

    return result


print(cryptic_sorter(["hello", "world", "hi", "test"]))
print(cryptic_sorter(["Bb", "aA", "ba", "AB"]))
print(cryptic_sorter(["dog", "God", "cat", "Cat"]))