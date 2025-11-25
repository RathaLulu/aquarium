import json
import time
from queue import Queue


class aqua_reader:
 
    def __init__(self, filename): 
        self.data = dict()
        try:
            with open(filename, "r", encoding="utf-8") as f:
                self.data = json.load(f)
        except FileNotFoundError:
            print("Fichier non trouvé !")
        except json.JSONDecodeError:
            print("Fichier JSON invalide !")

    def getFullData(self): 
        return self.data

    def getEpoch(self, Epoch) : 
        if Epoch >= 1 : 
            return self.data[Epoch - 1]
        else : 
            raise ValueError("Epoch < 1 ") 

    def getDataFlux(self, queue) :
        for Epoch in self.data : 
            queue.put(Epoch)
            time.sleep(0.01)



if __name__ == "__main__":
    filename = f'/home/lucas/code/aquarium/data/test.json'
    reader = aqua_reader(filename)
    q = Queue()
    reader.getDataFlux(q)
    for i in range(40) :
        epoch = q.get()
        print(epoch)

    
    