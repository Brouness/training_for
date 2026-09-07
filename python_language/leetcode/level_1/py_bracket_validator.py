def bracket_validator(s: str) -> bool:
    pairs = {')':'(', ']':'[', '}':'{'}
    stack = []
    for char in s:
        if char in "({[":
            stack.append(char)
        elif char in pairs:
            if not stack or stack.pop() != pairs[char]:
                return False
    return len(stack) == 0

print(bracket_validator("()"))
print(bracket_validator("()[]{}"))
print(bracket_validator("()[]{}"))
