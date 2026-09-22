"""
1.2 — Method vs. attribute
Write a function describe_string(s) that returns a string report: the original string,
the uppercase version, and whether it equals its own lowercase version.
No lambda, no shortcuts — just make sure every method call actually has ().
"""

def describe_string(s):
	string = s.lower()
	if (string == s):
		report = f"{s} is equal to its uppercase"
	else:
		report = f"{s} is not equal to its uppercase"
	return s, string, report


print(type(describe_string("YOUNESS")))