def helper(text: str) -> bool:
    compared = text.replace(" ", "")
    if compared[::-1].lower() == compared.lower():
        return True
    else:
        return False

def echo_validator(text: str) -> bool:
    return helper(text)

print(echo_validator("racecar"))
print(echo_validator("A man a plan a canal Panama"))
print(echo_validator("race a car"))
print(echo_validator("Was it a car or a cat I saw"))
print(echo_validator("hello"))
