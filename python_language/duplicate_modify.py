"""
1.1 — Alias trap
Write a function duplicate_and_modify(lst) that takes a list, creates what you believe 
is a separate copy, appends the number 99 to the copy, and returns both the original and the copy. Print both after 
calling it. Predict on paper what you expect before running it — then see if reality matches. 
(This directly targets your copy = strings bug.)
"""

def duplicate_and_modify(lst):
	if lst is None:
		return []
	x = []
	x = lst.copy()
	x.append(99)
	return x,lst


original = [1, 2, 3, 4, 5, 6]
copy_result, original_result = duplicate_and_modify(original)
print("copy:", copy_result)
print("original after call:", original_result)
print("is original still untouched?", original == original_result)
