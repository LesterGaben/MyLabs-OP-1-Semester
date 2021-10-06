import math 

d = float(input("Довжина окола: ")) 
y = math.pi
S = y*((d/(2*y))**2) 
m = "Площа кола: {}"
print(m.format(S)) 
