class Zone:
    def __init__(self, name: str, x: int, y: int, zone_type="normal"):
        self.name = name
        self.x = x
        self.y = y
        self.zone_type = zone_type

    def movement_cost(self) -> int:
        if (self.zone_type == "normal" or self.zone_type == "priority"):
            return 1
        elif(self.zone_type == "restricted"):
            return 2
        elif (self.zone_type == "blocked"):
            return 0
        else:
            raise ValueError(f"Unknown zone type: {self.zone_type}")

    def describe(self) -> str:
        return (f"{self.name} at ({self.x}, {self.y})")

zone1 = Zone("Zone1", 1, 1)
print(zone1.describe())
print(zone1.movement_cost())
zone1.zone_type = "blocked"
print(zone1.movement_cost())
