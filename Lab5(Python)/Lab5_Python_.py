n = int(input("Введите натуральное число: "))
i = 1
N = n

print("Натуральные числа, которые меньше введённого числа и взаимно простые с ним: ")
for i in range(n):
  m=i
  while m != 0 and N != 0:
    if m > N:
        m = m % N
    else:
        N = N % m

  if (N + m) == 1:
      print (i)
  N=n