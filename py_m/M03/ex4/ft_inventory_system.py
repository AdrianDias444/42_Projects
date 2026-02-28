import sys

class Negative_Error(Exception):
    pass
def Raise_Negative_Error(nb:int):
    if(nb < 0):
        raise Negative_Error("Este numero e negativo, pode nao pai")

class Inventory_Manager():
    def __init__(self):
        pass
    def create_inventory(self, argv:str):
        inventory = {}
        for i in argv:
            extract = i.split(':')
            try:
                nb = int(extract[1])
                Raise_Negative_Error(nb)
                inventory.update({extract[0]: extract[1]})
            except ValueError:
                print("Ne numero nao pai")
            except Negative_Error as e:
                print (e)
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

    def inventory_statistic(self, inventory):
        print("\n=== Inventory Statistics ===")
        lst = list(inventory.items())
        max = 0
        for i in lst:
            nb = int(i[1])
            if (max < nb):
                max = nb
        #print(f"Max is {max}")
        min = max
        for i in lst:
            nb = int(i[1])
            if(min > nb):
                min = nb
        #print(f"Min is {min}")
        i = 0
        while(int(lst[i][1]) is not max):
            i += 1
        j = 0
        while(int(lst[j][1]) is not min):
            j += 1
        max_value = inventory.get(lst[i][0])
        min_value = inventory.get(lst[j][0])

        print(f"Most abundant: {lst[i][0]} ({max_value} units)")
        print(f"Least abundant: {lst[j][0]} ({min_value} units)")

    def item_categories(self, inventory):
        print("=== Item Categories ===")
        lst = {
            'Moderate': {},
            'Scarce': {},
            'Restock': {}
        }
        for i in inventory.items():
            if(int(i[1]) > 3):
                lst['Moderate'].update({i[0]:i[1]})
            else:
                lst['Scarce'].update({i[0]:i[1]})
                if(int(i[1]) < 2):
                    lst['Restock'].update({i[0]:i[1]})

        print(f"Moderate: {lst['Moderate']}")
        print(f"Scarce: {lst['Scarce']}")
        return (lst['Restock'])
    
    def management_suggestions(self, suggest_list):
        print("\n=== Management Suggestion ===")
        lst = list(suggest_list.items())
        restock = []
        for i in lst:
            restock.append(i[0])
        print("Restock needed: ", end="")
        i = 0
        while(i < len(restock)):
            if(not (i + 1 < len(restock))):
                print (restock[i])
                return
            print(restock[i], end=", ")
            i += 1

    def dictionary_properties(self, inventory):
        print("\n=== Dictionary Properties Demo ===")
        lookup = "sword"
        lst_keys = list(inventory.keys())
        lst_values = list(inventory.values())

        i = 0
        print("Dictionary keys: ", end="")
        while(i < len(lst_keys) - 1):
            print(lst_keys[i], end=", ")
            i += 1
        print(lst_keys[i])

        print("Dictionary values: ", end="")
        i = 0
        while(i < len(lst_values) - 1):
            print(lst_values[i], end=", ")
            i += 1
        print(lst_values[i])

        for i in lst_keys:
            if(lookup == i):
                print(f"Sample lookup - '{lookup}' in inventory: True")
                return
        print(f"Sample lookup - '{lookup}' in inventory: False")

if __name__ == "__main__":
    if (len(sys.argv) > 1):
        print("=== Inventory System Analysis ===")
        manager = Inventory_Manager()

        arg = sys.argv
        inventory = manager.create_inventory(arg[1:])
        manager.print_current_inventory(inventory)

        manager.inventory_statistic(inventory)

        print()
        restock = manager.item_categories(inventory)

        manager.management_suggestions(restock)

        manager.dictionary_properties(inventory)
# dict.keys()
# dict.values()
# dict.items()
# dict.get()
# dict.update()