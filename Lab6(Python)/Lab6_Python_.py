import math


def integral_sum(a, b, n):
    sum = integral_arctg(a, b, n) + integral_sin(0, math.pi, n)
    return sum



def integral_arctg(a, b, n):
    h = (b - a) / n
    arctg = 0
    for i in range(1, n, 1):
        arctg += pow(math.atan(a + i * h), 2)
    arctg_1 = (pow(math.atan(a), 2) + pow(math.atan(b), 2)) / 2 + arctg
    arctg_1 = int(arctg_1)
    arctg_2 = arctg_1 * h
    return arctg_2


def integral_sin(a, b, n):
    h = (b - a) / n
    sin = 0
    for i in range(1, n, 1):
        sin += math.sin(pow(math.e,(10 * (a + i * h))))
    sin_1 = (math.sin(pow(math.e, (10 * a))) + math.sin(pow(math.e, (10 * b)))) / 2 + sin
    sin_1 = int(sin_1)
    sin_2 = sin_1 * h
    return sin_2


a = int(input("Введите целое число a: "))
b = int(input("Введите целое число b: "))
n = int(input("Введите целое число, большее или равное 1: "))

while (n < 1):
    n = int(input("Введите целое число, большее или равное 1: "))

print("Приблизительная сумма интегралов: " + str(integral_sum(a,b,n)))