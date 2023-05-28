from helloworld import *
from longestCommonPrefix import *

helloWorld()
print(longestCommonPrefix(["Flower", "Fly", "Flee", "Fl" ])) # Fl
print(longestCommonPrefix(["FL", "Flower", "Fly", "Flee", "Fl" ])) # F
print(longestCommonPrefix(["F", "Flower", "Fly", "Flee", "Fl" ])) # F
print(longestCommonPrefix(["Fyds", "Flower", "Fly", "Flee", "Fl" ])) # F
print(longestCommonPrefix(["Fs", "Flower", "Fly", "Flee", "Fl" ])) # F
print(longestCommonPrefix(["Flower", "Fly", "Flee", "Fl", "fkdls" ])) # None
print(longestCommonPrefix(["Flower", "Fly", "Flee", "Fl", "f" ])) # None
print(longestCommonPrefix(["Flower", "Fly", "FL", "Flee", "Fl" ])) # F
print(longestCommonPrefix(["Flower", "Fly", "Fw", "Flee", "Fl" ])) # F
print(longestCommonPrefix(["Flower", "Fly", "Fdsw", "Flee", "Fl" ])) # F