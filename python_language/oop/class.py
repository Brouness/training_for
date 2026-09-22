class Person:
	def __init__(self, name, age):
		self.name = name
		self.age = age
	def greet(self) -> None:
		print(f"Hello, my name is {self.name} and i have {self.age}")

p1 = Person("jhon", 63)
p1.greet()

class Dog:
	def __init__(self, name, age):
		self.name = name
		self.age = age
	def bark(self):
		print(f"{self.name} says Woof!")
# Create an object
d1 = Dog("Buddy", 3)
# Call the bark method
d1.bark()
# Create the Car class
class Car:
	def __init__(self, brand):
		self.brand = brand
	def show(self):
		print(self.brand)
# Create an object
c1 = Car("Ford")
# Call the show method
c1.show()

# Create the Student class
class Student:
	def __init__(self, name, grade):
		self.name = name
		self.grade = grade
# Create an object
s1 = Student("Anna", "A")
# Print the grade
print(s1.grade)
# Change the grade
s1.grade = "B"
# Print the updated grade
print(s1.grade)

# Create the Rectangle class
class Rectangle:
	def __init__(self, width, height):
		self.width = width
		self.height = height
	def area(self):
		return self.width * self.height
# Create an object
r1 = Rectangle(5, 3)
# Print the area
print(r1.area())
