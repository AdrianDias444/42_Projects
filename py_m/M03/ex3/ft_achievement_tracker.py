class Player():
    def __init__(self, player_name:str, achievements):
        self.player_name = player_name
        self.achievements = achievements
    def get_info(self):
        print(f"Player {i.player_name} achievements: {i.achievements}")

class Achievement_Manager():
    def __init__(self):
        pass
    def all_achievements(self, lst_players):
        z = set([])
        for i in lst_players:
            z = z.union(i.achievements)
        print(f"All unique achievements: {z}")
        print(f"Total unique achievements: {len(z)}")
    
    def common_to_all(self, lst_players):
        z = lst_players[0].achievements
        for i in lst_players:
            z = z.intersection(i.achievements)
        print(f"Common to all players: {z}")

    def rare_achievements(self, lst_players):
        lst_final= []
        for i in lst_players:
            lst_final.extend(i.achievements)
        j = 0
        while(j < len(lst_final)):
            elemento = lst_final[j]
            count = 0
            z = 0
            while(z < len(lst_final)):
                if(lst_final[z] == elemento):
                    count += 1
                z+=1
            if (count > 1):
                lst_final = [x for x in lst_final if x != elemento]
            else:
                j += 1
        print(f"Rare achievement (1 player): {set(lst_final)}\n")

    def player_communities(self, lst_player):
        common = lst_player[0].achievements.intersection(lst_player[1].achievements)

        alice_unique = lst_player[0].achievements.difference(lst_player[1].achievements)

        bob_unique = lst_player[1].achievements.difference(lst_player[0].achievements)

        print(f"{lst_player[0].player_name} vs {lst_player[1].player_name} common: {common}")
        print(f"Alice unique: {alice_unique}")
        print(f"Bob unique: {bob_unique}")



if __name__ == "__main__":
    print("=== Achievement Tracker System ===")
    alice = Player("alice", set(['first_kill', 'level_10','treasure_hunter', 'speed_demon']))

    bob = Player("bob", set(['first_kill', 'level_10', 'boss_slayer', 'collector']))

    charlie = Player("charlie", set(['level_10', 'treasure_hunter', 'boss_slayer', 'speed_demon', 'perfectionist']))


    lst = [alice, bob, charlie]

    for i in lst:
        i.get_info()
    print("\n=== Achievement Analytics ===")
    manager = Achievement_Manager()
    manager.all_achievements(lst)
    print()
    manager.common_to_all(lst)
    manager.rare_achievements(lst)
    manager.player_communities(lst)