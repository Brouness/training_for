"""
Write a function that checks if the brackets in a string are valid.

A string is valid if every ipening brackets has a matching closing bracket

Allowed brackets: (), [], {}.
"""
# def     bracket_validator(s: str) -> bool:
#     i = 0
#     my_list = ['(', ')', '[', ']', '{', '}']
#     new_list = []
#     while (i < len(s)):
#         if (s[i] in my_list):
#             new_list.append(s[i])
#         i += 1
#     i = 0
#     while (len(new_list) > 1):
#         if (new_list and new_list[i] == '('):
#             if (new_list[len(new_list) - 1] != ')' and new_list[i + 1] != ')'):
#                 return False
#             else:
#                 new_list.pop(i)
#                 if (new_list[i] == ')'):
#                     new_list.pop(i)
#                 else:
#                     new_list.pop(len(new_list) - 1)
#                 i = 0
#         if (new_list and new_list[i] == '['):
#             if (new_list[len(new_list) - 1] != ']' and new_list[i + 1] != ']'):
#                 print("here")
#                 return False
#             else:
#                 new_list.pop(i)
#                 if (new_list[len(new_list) - 1] == ']'):
#                     new_list.pop(len(new_list) - 1)
#                 else:
#                     new_list.pop(i)
#                 i = 0
#         if (new_list and new_list[i] == '{'):
#             if (new_list[len(new_list) - 1] != '}' and new_list[i + 1] != '}'):
#                 return False
#             else:
#                 new_list.pop(i)
#                 if (new_list[len(new_list) - 1] == '}'):
#                     new_list.pop(len(new_list) - 1)
#                 else:
#                     new_list.pop(i)
#                 i = 0
#     if (new_list):
#         return False
#     return True



# print("bracket_validator(()())")
# print(bracket_validator("()()"))

def bracket_validator(s: str) -> bool:
    pairs = {')': '(', '}': '{', ']': '['}
    stack = []
    for char in s:
        if char in "({[":
            stack.append(char)
        elif char in pairs:
            if not stack or stack.pop() != pairs[char]:
                return False    
    return len(stack) == 0
