def convert_base(number: str, from_base: int, to_base: int) -> str:
    big_base = "0123456789ABCDEFJHIJKLMNOPQRSTUVWXYZ"
    my_list = []
    if not 2 <= from_base <= 36 or not 2 <= to_base <= 36:
        return "Error"
    try:
        n = int(number, from_base)
    except ValueError:
        return "Error"
    
    if n < 0:
        ch = "-"
        n = abs(n)
    else:
        ch = ""
    
    while n > 0:
        my_list.append(big_base[n % to_base])
        n //= to_base
    my_list.append(ch)
    return "".join(my_list)[::-1]

print("Basic")
print(f"'A',16,10=10: {convert_base("A", 16, 10)}")
print(f"'1010',2,10=10: {convert_base("1010", 2, 10)}")
print(f"'10',10,2=1010: {convert_base("10", 10, 2)}")
print(f"'1A',16,10=26: {convert_base("1A", 16, 10)}")

print("\nEdge")
print(f"'123',10,10=123: {convert_base("123", 10, 10)}")
print(f"'0',10,2=0: {convert_base("0", 10, 2)}")
print(f"'000',2,10=0: {convert_base("000", 2, 10)}")

print("\nLarge")
print(f"'ZZZ',36,10=46655: {convert_base("ZZZ", 36, 10)}")
print(f"'46655',10,36=ZZZ: {convert_base("46655", 10, 36)}")

print("\nMixed")
print(f"'1F4',16,10=500: {convert_base("1F4", 16, 10)}")
print(f"'500',10,16=1F4: {convert_base("500", 10, 16)}")

print("\nInvalid")
print(f"'2',2,10=ERROR: {convert_base("2", 2, 10)}")
print(f"'G',16,10=10: {convert_base("G", 16, 10)}")

print("\nNegative")
print(f"'-A',16,10=10: {convert_base("-A", 16, 10)}")
print(f"'-1010',2,10=10: {convert_base("-1010", 2, 10)}")
print(f"'-10',10,2=1010: {convert_base("-10", 10, 2)}")
print(f"'-1A',16,10=26: {convert_base("-1A", 16, 10)}")
print()