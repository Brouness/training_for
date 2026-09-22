"""
2.1 — Two-string comparator
Write compare_by_length(a, b) that returns -1 if a is shorter, 1 if b is shorter, 0 if equal length.
Test it on at least 5 pairs by hand before trusting it.
"""


def compare_by_length(a, b):
	if len(a) < len(b):
		return -1
	elif len(a) > len(b):
		return 1
	else:
		return 0
