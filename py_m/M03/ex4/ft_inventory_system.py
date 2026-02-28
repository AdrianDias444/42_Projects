import sys

class Inventory_Manager():
    def __init__(self):
        pass
    def create_inventory(self, argv:str):
        inventory = {}
        for i in argv:
            extract = i.split(':')
            try:
                int(extract[1])
                inventory.update({extract[0]: extract[1]})
            except ValueError:
                print("Ne numero nao pai")
        #print(inventory)
        return(inventory)

    def print_current_inventory(self, inventory):
        lst = list(inventory.items())
        total_items = 0
        total_unique_items = 0
        for i in lst:
            total_items += int(i[1])
            total_unique_items += 1
        print(f"Total items in inventory: {total_items}")
        print(f"Unique item types: {total_unique_items}\n")
        print("=== Current Inventory ===")
        i = 0
        while(i < len(lst)):
            print(f"{lst[i][0]}: {lst[i][1]} units ({int(lst[i][1])/total_items*100:.2f})")
            i += 1

    def inventory_statistic(self):
        
if __name__ == "__main__":
    if (len(sys.argv) > 1):
        print("=== Inventory System Analysis ===")
        manager = Inventory_Manager()

        arg = sys.argv
        inventory = manager.create_inventory(arg[1:])
        manager.print_current_inventory(inventory)

        

# dict.keys()
# dict.values()
# dict.items()
# dict.get()
# dict.update()