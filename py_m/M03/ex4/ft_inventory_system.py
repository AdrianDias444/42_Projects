import sys

class Inventory_Manager():
    def __init__(self):
        pass
    def create_inventory(self, argv):
        inventory = {}
        for i in argv:
            extract = i.split(':')
            try:
                chave = extract[0]
                valor = int(extract[1])
                inventory[chave] = valor
          
            except ValueError:
                print("Ne numero nao pai")
        print(inventory)
        print(inventory.values())

if __name__ == "__main__":
    if (len(sys.argv) > 1):
        print("=== Current Inventory")
        manager = Inventory_Manager()

        arg = sys.argv
        manager.create_inventory(arg[1:])