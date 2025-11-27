import json
import time
from queue import Queue


class aqua_reader:
 
    def __init__(self, filename): 
        self.__data = dict()
        try:
            with open(filename, "r", encoding="utf-8") as f:
                self.__data = json.load(f)
                self.size = len(self.__data)
        except FileNotFoundError:
            print("Fichier non trouvé !")
        except json.JSONDecodeError:
            print("Fichier JSON invalide !")


    def getFullData(self): 
        return self.__data

    def getEpoch(self, Epoch) : 
        if Epoch >= 1 and Epoch <= self.size: 
            return self.__data[Epoch - 1]  #Epoch - 1 car Epoch (tour) commence par 1 dans les fichiers json 
        else : 
            raise ValueError("Epoch non valide") 
    
    def getEpochFlux(self, queue, Epoch): 
        if Epoch >= 1 and Epoch <= self.size: 
            queue.put(self.__data[Epoch - 1])
        else : 
            raise ValueError("Epoch non valide") 
        

    def getFullDataFlux(self, queue) :
        for Epoch in self.__data : 
            queue.put(Epoch)
            time.sleep(0.01)



if __name__ == "__main__":
    filename = f'/home/lucas/code/aquarium/data/test.json'
    reader = aqua_reader(filename)
    q = Queue() 
    for i in range(1,43) :
        reader.getEpochFlux(q,i)
        epoch = q.get()
        print(f'{epoch}\n')

    
    