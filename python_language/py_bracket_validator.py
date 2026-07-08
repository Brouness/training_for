"""
Write a function that checks if the brackets in a string are valid.

A string is valid if every opening bracket has a matching closing bracket
in the correct order.

Allowed brackets: (), [], {}

Function signature

def bracket_validator(s: str) -> bool:
"""

def bracket_validator(s: str) -> bool:
    if s is None:
        return True

    pairs = {')': '(', ']': '[', '}': '{'}
    stack = []

    for char in s:
        if char in '([{':
            stack.append(char)
        elif char in ')]}':
            if not stack or stack.pop() != pairs[char]:
                return False

    return len(stack) == 0


print(bracket_validator("()"))       # True
print(bracket_validator("()[]{}"))   # True
print(bracket_validator("(]"))       # False
print(bracket_validator("([)]"))     # False
print(bracket_validator("{[]}"))
print(bracket_validator("hello(world)"))
print(bracket_validator("((())"))
print(bracket_validator(""))