from dataclasses import dataclass

@dataclass(slotes=True)
class car:
    """Class for keeping track of an item in inventory."""
    name: str
    modele: int
    hors_power: int

bmw = car("bmw_m5", "2024", 95)

print(bmw.name)
print(bmw.hors_power)
print(bmw.modele)