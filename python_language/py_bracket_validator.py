def bracket_validator(s: str) -> bool:
    if s == None:
        return True
    i = 0
    if '{' in s and not '}' in s:
        return False
    elif '(' in s and not ')' in s:
        return False
    elif '[' in s and not ']' in s:
        return False
    return True



print(bracket_validator("()[]{}"))
print(bracket_validator("(]"))
print(bracket_validator("([)]"))
print(bracket_validator("{[]}"))
print(bracket_validator("hello(world)"))
print(bracket_validator("((())"))
print(bracket_validator(""))

