import cs50
from cs50 import get_string

name = get_string("What is your name: ")

print(f"hello, {name.title()}")