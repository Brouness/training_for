class Vehicle:
    def __init__(self, name: str):
        self.name = name
    
    def move(self) -> str:
        return f"{self.name} moves"
    
    
class Drone(Vehicle):
    def __init__(self, name:str, max_speed: int):
        super().__init__(name)
        self.max_speed = max_speed

    def move(self) -> str:
        return f"{self.name} flies with {self.max_speed}KM/H"

x = Drone("drone", 120)
print(x.move())