def whisper_cipher(text: str, shift: int) -> str:
    my_list = []
    for c in text:
        if c isalpha():
            start = 'A' if c.isupper() else 'a'
            my_list.append(chr((ord(c) - ord(start) + shift) % 26 + ord(start)))
        else:
            my_list.append(c)
    return "".join(my_list)
