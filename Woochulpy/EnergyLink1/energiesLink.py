filePath = "Woochulpy/EnergyLink1/" #leave blank if not necessary
#file names
energyFileName = filePath + "ener.txt"
numbersFileName = filePath + "nmr.txt"

#userSetNumbers: user may select preferences for these numbers
dataPerEnergy = 48  #how many data values per energy value
indexToStartSorting = 0  #set to zero if the whole list isn't sorted, and set to index n if certain the first n numbers are sorted. Generally, leave this at zero

#creation of a class to link energy values with data
class EnergyData:
    def __init__(self, energy):
        #instatiating class with an energy and corresponding array of integer dataPerEnergy length/size
        self.energy = energy
        self.data = [0] * dataPerEnergy

list = [] #declaration of our list of Energy Values
linesEnergy = open(energyFileName).read().splitlines() #read the file every line-by-line into this list
for line in linesEnergy:
    list.append( EnergyData(line) ) #append each line into the energy field of the corresponding energy into a list of energy classes

#CheckPoints
print("Program: Appended Energy Values")

linesNumbers = open(numbersFileName).read().splitlines() #
lineCount = 0
for i in range(len(list)):
    for j in range(dataPerEnergy):
        index= i * dataPerEnergy + j
        list[i].data[j] = linesNumbers[index]

#CheckPoints
print("Program: Appended Data Values")

""" Sorting Algorithm:
The general idea here is that I need to circulate through the entire list and pick out the most minimum/negative number. Once I pick out that number,
I need to move it to the front of the list, and start circulating again for everything excluding that sorted value, since it is already at the start.
I keep dragging the most minimum number out in front of the previous minimum number until I reach the last number, which evidently is the greatest,
so it is sorted from most negative to max. """
#we sort every index but the last one, since once sorted, the last index is bound to be the greatest
for i in range(indexToStartSorting, len(list)-1):
    #declaring my minimum to the first index
    min = float(list[i].energy)
    minIndex = i
    #searching everything after the first index and comparing to see if it is less than it, if it is, it becomes new minimum to be compared against
    for i1 in range(i+1, len(list)): #named i1 because it circulates through every index 1 above i
        if (float(list[i1].energy) < min):
            min = float(list[i1].energy)
            minIndex = i1
    #remove Energy value at where it was and insert at front of list where it is last sorted
    temp = list[minIndex]
    list.remove(list[minIndex])
    list.insert(i, temp)

#CheckPoints
print("Program: Sorted the List of Energy Values")

def outputNLinesToFile(n, list):
    #The File is doesn't have to exist, as it will create or overwrite a file. User feel free to change the file name or path for output
    fileName = filePath + "lowest_" + n + "data.txt" 

    outputFile = open(fileName, "w+")
    for energyIndex in range(int(n)):
        outputFile.write("Energy: " + list[energyIndex].energy + "\n")
        outputFile.write("Corresponding Data: " + "\n")
        for dataIndex in range(dataPerEnergy):
            outputFile.write(list[energyIndex].data[dataIndex] + "\n")
        outputFile.write("\n") #newLine after every energy

#User Input/Interaction
response = "y"
while (response != "n"):
    inp = input("How many energy values (sorted lowest to highest) would you like to see data for (typing zero creates an empty txt file, just don't)? ")
    outputNLinesToFile(inp, list)
    print("File created:", "lowest_" + inp + "data.txt")
    resp = input("Would you like to create another one of these files? (y/n): ")
    response = resp.lower()



#test, REMOVE PLEASE
# for x in range(len(list)):
#     print("SortList", x, list[x].energy)


#w+ mode truncates file, so it clears it for writing into