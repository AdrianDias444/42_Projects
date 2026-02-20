
class GardenManager():
    def __init__(self, name:str, number:int):
        self.name = name
        self.plants = []
        self.number = number

    def add_plant_to_garden(self, plant:Plant):
        self.plants.append(plant)
        self.number += 1
        print(f"Added {plant.name} to {self.name} Garden")
    
    def grow_all_plants(self, j:int):
        print(f"{self.name} is helping all plants grow...")
        for i in range(self.number):
            self.plants[i].height += j
            print(f"{self.plants[i].name} grew {j} cm")

    @classmethod
    def create_garden_network(cls, garden_data):
        gardens = []
        for garden_name, plants_list in garden_data:
            garden = cls(garden_name, 0)
            for plant in plants_list:
                garden.add_plant_to_garden(plant)
            gardens.append(garden)
        return gardens
    
    
    class GardenStats:
        def __init__(self, plants):
            self.plants = plants
            total = 0
            for planta in plants:
                total += 1
            self.total_plants = total

            soma = 0
            for planta in plants:
                soma += (planta.height - planta.initial_height)
            self.total_growth = soma

            self.plant_nb = 0
            self.flower_nb = 0
            self.prize_flower_nb = 0

            for planta in plants:
                if(planta.plant_type == "plant"):
                    self.plant_nb += 1
                elif(planta.plant_type == "flower"):
                    self.flower_nb += 1
                elif(planta.plant_type == "prized flower"):
                    self.prize_flower_nb += 1
    def get_stats(self):
        return self.GardenStats(self.plants)

class Plant():
    def __init__(self, name:str, height:int):
        self.name = name
        self.height = height
        self.initial_height = height
        self.plant_type = "plant"
    def grow(self):
        self.height += 1
        print(f"{self.name} grew 1cm")

class FloweringPlant(Plant):
    def __init__(self, name:str, height:int, color:str, bloom:bool):
        super().__init__(name, height)
        self.color = color
        self.bloom = False
        self.plant_type = "flower"
    def bloom_plant(self):
        self.is_blooming = True
        print(f"The flower {self.name} is blooming")

class PrizeFlower(FloweringPlant):
    def __init__(self, name:str, height:int, color:str, bloom:str, points:int):
        super().__init__(name, height, color, bloom)
        self.points = points    
        self.plant_type = "prized flower"
    def prized(self):
        self.points += 10

if __name__ == "__main__":
    print("=== Garden Management System Demo ===\n")

    oak = Plant("Oak Tree", 101)
    rose = FloweringPlant("Rose", 26, "red", False)
    sunflower = PrizeFlower("Sunflower", 51, "yellow", False, 10)
    cactus = Plant("Cactus", 15)
    tulip = FloweringPlant("Tulip", 20, "pink", False)

    dados_jardins = [
        ("Alice", [oak, rose, sunflower]),
        ("Adrian", [cactus, tulip])
    ]

    print("--- Criando rede de jardins ---")
    jardins = GardenManager.create_garden_network(dados_jardins)


    alice_garden = jardins[0]
    bob_garden = jardins[1]

    print(f"\n=== {alice_garden.name}'s Garden Report ===")
    print("Plants in garden:")
    for planta in alice_garden.plants:
        if planta.plant_type == "prized flower":
            print(f"- {planta.name}: {planta.height}cm, {planta.color} flowers, Prize points: {planta.points}")
        elif planta.plant_type == "flower":
            print(f"- {planta.name}: {planta.height}cm, {planta.color} flowers")
        else:
            print(f"- {planta.name}: {planta.height}cm")

    alice_score = 0
    for p in alice_garden.plants:
        alice_score += p.height
    
    bob_score = 0
    for p in bob_garden.plants:
        bob_score += p.height
    
    print(f"\nGarden scores - Alice: {alice_score}, Bob: {bob_score}")
    print(f"Total gardens managed: {len(jardins)}\n")