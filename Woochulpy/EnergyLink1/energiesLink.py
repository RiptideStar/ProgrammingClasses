dataPerEnergy = 48
#creation of a class to link energy values with data
class EnergyData:
    def __init__(self, energy):
        self.energy = energy
        self.data = [0] * dataPerEnergy

filePath = "Woochulpy/EnergyLink1"
#file names
energyFileName = filePath + "/ener.txt"
numbersFileName = filePath + "/nmr.txt"

list = []
linesEnergy = open(energyFileName).read().splitlines()
for line in linesEnergy:
    list.append( EnergyData(line) )

print("Appended Energy Values (WORKS!)")

linesNumbers = open(numbersFileName).read().splitlines()
lineCount = 0
for i in range(len(list)):
    for j in range(dataPerEnergy):
        index= i*dataPerEnergy + j
        list[i].data[j] = linesNumbers[index]

print("Appended Data Values")







        
