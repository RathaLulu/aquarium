import json

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
    def getData(self): 
        return self.data

if __name__ == "__main__":
    filename = f'/home/lucas/code/aquarium/data/test.json'
    reader = aqua_reader(filename)
    data = reader.getData()
    print(data)
    
    