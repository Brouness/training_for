from enum import Enum

class Names(Enum):
    YOUNESS: str = "Youness bourajli"
    HAMID: str = "Hamid lamrani allawi"

class Week(Enum):
    SUNDAY: int = 0
    MONDAY: int = 1
    TUESDAY: int = 2
    WEDNESDAY: int = 3

if __name__ == "__main__":
    for day in Week:
        print(day.value, "-", day)
    for name in Names:
        print(name.value, "-", name)
