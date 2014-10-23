import sys
'''
def findModulo(number,devisor):
    temp =int(number)
    while (temp > int(devisor)):
        temp = temp - int(devisor)
        if(temp == devisor):
            return 0
    return temp
'''

ifile = open("test.txt")
for line in ifile:
    newArray = line.split(',')
    if len(newArray) < 3:
        print(str(int(newArray[0])%int(newArray[1])))