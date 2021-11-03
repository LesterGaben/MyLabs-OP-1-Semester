n = int(input("Введите натуральное число: "))
i = 1
b = n

print("Натуральные числа, которые меньше введённого числа и взаимно простые с ним: ")
for i in range(n):
  m=i
  while m != 0 and b != 0:
    if m > b:
        m = m % b
    else:
        b = b % m

  if (b + m) == 1:
      print (i)
  b=n