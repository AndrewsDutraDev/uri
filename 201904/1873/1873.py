c = int(input())

for i in range(c):
    s1, s2 = input().split()
    if (s1 == s2):
        print("empate")
    elif (s1 == "tesoura" and s2 == "papel"):
        print("rajesh")
    elif (s2 == "tesoura" and s1 == "papel"):
        print("sheldon")
    elif (s1 == "papel" and s2 == "pedra"):
        print("rajesh")
    elif (s2 == "papel" and s1 == "pedra"):
        print("sheldon")
    elif (s1 == "pedra" and s2 == "lagarto"):
        print("rajesh")
    elif (s1 == "lagarto" and s2 == "pedra"):
        print("sheldon")
    elif (s1 == "lagarto" and s2 == "spock"):
        print("rajesh")
    elif (s1 == "spock" and s2 == "lagarto"):
        print("sheldon")
    elif (s1 == "spock" and s2 == "tesoura"):
        print("rajesh")
    elif (s2 == "spock" and s1 == "tesoura"):
        print("sheldon")
    elif (s1 == "tesoura" and s2 == "lagarto"):
        print("rajesh")
    elif (s2 == "tesoura" and s1 == "lagarto"):
        print("sheldon")
    elif (s1 == "lagarto" and s2 == "papel"):
        print("rajesh")
    elif (s1 == "papel" and s2 == "lagarto"):
        print("sheldon")
    elif (s1 == "papel" and s2 == "spock"):
        print("rajesh")
    elif (s1 == "spock" and s2 == "papel"):
        print("sheldon")
    elif (s1 == "spock" and s2 == "pedra"):
        print("rajesh")
    elif (s1 == "pedra" and s2 == "spock"):
        print("sheldon")
    elif (s1 == "pedra" and s2 == "tesoura"):
        print("rajesh")
    elif (s1 == "tesoura" and s2 == "pedra"):
        print("sheldon")
