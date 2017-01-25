#                               ---DEV SUBHAJIT ---
#                               CREATED ON
import time
import winsound
import random
from threading import Timer
#class for inventory
class Inventory :
    def __init__(self):
        self.water = 0
        self.bullet = 0
        self.bedsheets = 0
        self.clothes = 0
        self.mug = 0
        self.gun = 0
        self.food = 0
        self.money = 0
        self.items = self.water + self.bullet + self.bedsheets + self.clothes + self.food
    def upgrade_water(self):
        if self.items <= 5:
            self.water = self.water + 1
            print("No of water bottles available are ")
            print(self.water)
        else:
            print("The inventory is full")

    def upgrade_bullet(self):
        if self.items <= 5:
            self.bullet = self.bullet + 1
            print("No of bullets available are ")
            print(self.bullet)
        else:
            print("The inventory is full")

    def upgrade_bedsheets(self):
        if self.items <= 5:
            self.bedsheets = self.bedsheets + 1
            print("No of bedsheets available are ")
            print(self.bedsheets)
        else:
            print("The inventory is full")

    def upgrade_clothes(self):
        if self.items <= 5:
            self.clothes = self.clothes + 1
            print("No of clothes available are ")
            print(self.clothes)
        else:
            print("The inventory is full")

    def upgrade_mug(self):
        if self.items <= 5:
            self.mug = self.mug + 1
            print("No of mug available are ")
            print(self.mug)
        else:
            print("The inventory is full")

    def upgrade_gun(self):
        if self.items <= 5:
            self.gun = self.gun + 1
            print("No of gun available are ")
            print(self.gun)
        else:
            print("The inventory is full")

    def upgrade_food(self):
        if self.items <= 5:
            self.food = self.food + 1
            print("No of food available are ")
            print(self.food)
        else:
            print("The inventory is full")

    def money(self):
        self.money = 50

    def check_gun(self):
        if self.gun > 0:
            return True
        else:
            return False

    def check_bullet(self):
        if self.bullet > 0:
            return True
        else:
            return False

    def check_money(self,price):
        self.money = self.money - price

object_Inventory = Inventory()          #object for class inventory
'''
#class for health
class health:
    def __init__(self):
        self.health = 15
    def update_health(self):
        self.health = self.health - 5
        print("Your health left is ")
        print(self.health)
    def check_health(self):
        if self.health <= 0:
            print("GAME OVER")
            return True
        else:
            return False

#object for class health
object_health = health()
'''
#function for bedroom
def bedroom():
    print("THIS IS THE BEDROOM")
    print("You have found the following items in the bedroom :\n1.BedSheet\n2.Clothes\n3.Money\n\n" +
                "Please select any item to add it to your Inventory list.")
    a = int(input())
    if a == 1:
        object_Inventory.upgrade_bedsheets()
        home()
    elif a == 2:
        object_Inventory.upgrade_clothes()
        home()
    elif a == 3:
        print("You have found 50$")
        home()
    else:
        print("You have entered wrong option")
        bedroom()

#~~~~~~~~~~~~~~~~~~~~~~BATHROOM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
def bathroom():
    print("THIS IS THE BATHROOM")
    print("You have found the following items in the bathroom :\n1.Mug\n2.Gun\n\n" +
                "Please select any item to add it to your Inventory list.")
    a = int(input())
    if a == 1:
        object_Inventory.upgrade_mug()
    elif a == 2:
        object_Inventory.upgrade_gun()
    else:
        print("You have entered wrong option")
        bathroom()

    home()

#~~~~~~~~~~~~~~~~~~~~~KITCHEN~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
def kitchen():
    print("THIs is the kitchen")
    print("You have found the following items in the kitchen :\n1.Food\n2.Water\n3.Bullet\n" +
          "Please select any item to add it your inventory list.")
    a = int(input())
    if a == 1:
        object_Inventory.upgrade_food()
    elif a == 2:
        object_Inventory.upgrade_water()
    elif a == 3:
        object_Inventory.upgrade_bullet()
    else:
        print("You have entered the wrong option")
        kitchen()

    home()

#~~~~~~~~~~~~~~~~~~~~~OUTSIDE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
def outside():
    print("Now you are on your way to the airport ...do u wanna search the other houses")
    print("1.Search the other houses")
    print("2.On the way to the airport")
    a = int(input())
    if a == 1:
        otherhouses()
    elif a == 2:
        airport()
    else:
        print("INVALID OPTION!!!")
        outside()

#~~~~~~~~~~~~~~~~~~OTHER HOUSES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
def otherhouses():
    print("There are two houses in front of you which one you wish to enter : 1 or 2")
    a = int(input())
    if a == 1:
        print("Zombie in this house...you have been attacked !!!...~~~YOU DIED~~~")
        exit()

    elif a == 2:
        print("You found a injured girl ...press 1 if u want to help her and press 2 if u dont")
        b = int(input())
        if b == 2:
            airport()
        elif b == 1:
            airport_including_girl()
        else:
            print("please press 1 or 2 to proceed")
            pass
    else:
        print("please enter correct input")
        otherhouses()

#~~~~~~~~~~~~~~~~~AIRPORT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

def airport():
    print("The boy reached the airport and the plan that was waiting there only had one seat left so he get into that plane")
    print("Soon after the plane departed the airport ...it got attacked by the zombies!!!")
    print("GAME OVER")

    #print("SIDE NOTE: i wonder what would happen if you have choose to help that girl(^~^)(thinking)")
    exit()

#~~~~~~~~~~~~~~~AIRPORT INCLUDING GIRL~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

def airport_including_girl():
    print("Now you have two path ")
    print("1.Left\n2.Right")
    a = int(input())
    print("Seems like ur game hanged :-P")
    time.sleep(7)
    if a == 1:
        print("While travelling this path they come across some others survivors like them ...")
        print("so they decided to settle down with them where they found a old acrade...")
        print("Wanna try them on??(y/n)??")
        ans = input()
        if ans == 'y' or ans == 'Y':
            sound_arcade_machine()
            minigame()
        print("")
        print("GAME COMPLETED")
        exit()
    elif a == 2:
        print("While moving down this path they encountered a petrol pump filled up with zombies")
        if(object_Inventory.check_bullet() and object_Inventory.check_gun()):
            print("Since you have both gun and bullet so you are able to find some time to slow down the zombies")
            print("and run towards the airport with girl")
            waiting_for_plane()
        else:
            print("You didnt have enough bullets or guns so we are killed by the zombies")
            print("~~~~~~~~GAME OVER~~~~~~~~~~")
            exit()
    else:
        print("You entered incorrect option please re-enter correctly")
        airport_including_girl()

#~~~~~~~~~~~~~~WAITING FOR PLANE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

def waiting_for_plane():
    print("While they are waiting for plane ..the airport got attacked by zombies")
    print("They both run together towards the Border of other city")
    print("Now they found out that the parents of both the boys and girls live in diff city")
    print("Now you have three choices")
    print("1. THey both go to there homes separately")
    print("2. The girl went with the boy to the boys hometown")
    print("3. The boy went with the girl to the girl hometown")
    option = int(input())
    if option == 1:
        function1()
    elif option == 2:
        function2()
    elif option == 3:
        function3()
    else:
        print("Wrong option please enter again")
        waiting_for_plane()

def function1():
    print("They went to there family respectively")
    print("The boy found there parents dead")
    print("He committed suicide after seeing that")
    print("The girl found her parents and left for some safe place")
    print("You want to play this game again (y/n)")
    ans = input()
    if ans == 'y' or ans == 'Y':
        home()
    elif ans == 'n' or ans == 'n':
        exit()
    else:
        print("please enter correct option")
        function1()

def function2():
    print("The girl went with the boy to the city where boys parents reside")
    print("They saw that the parents of boy died so they decided to move")
    print("1)towards the city where girls parents reside")
    print("2)to a new city and settled there")
    print("Enter a option")
    ans1 = int(input())
    if ans1 == 1:
        function3()
    elif ans2 == 2:
        print("they left for some place where its safe and settled there")                  #enter the story here on 4.1.17
        print("You want to play this game again (y/n)")
        ans = input()
        if ans == 'y' or ans == 'Y':
            home()
        elif ans == 'n' or ans == 'n':
            exit()
        else:
            pass
    else:
        print("Incorrect option plz enter it again")
        function2()

def function3():
    print("The boy went with the girl to the city where the girls parents reside")
    print("They found out that they are not there")
    print("So went to nearby city to search for her parents which will be continued in next part of the game")
    exit()

'''def shop():
    print("This is the shop what do you wanna buy from it")
    print("1.Bullet - 50$")
    print("")
    print("")
    a = int(input())
    if a == 1:
        object_Inventory.upgrade_bullet()
'''

#function for minigame_sum
def minigame_sum():
    print("You have 40 second lets c how much you are strong in maths")
    points = 0

    def Time_out():
        print("\nTimes up")
        print("Your point is \t")
        print(points)
        print("You want to play the minigame again(Y/N)")
        answer = input()
        if answer == 'y' or answer == 'Y':
            minigame()
        elif answer == 'n' or answer == 'n':
            exit()
        else:
            pass

    for i in range(0, 10000):
        a = random.randrange(1, 50)
        b = random.randrange(1, 50)
        print(a,'+',b)
        c = a + b
        t = Timer(40, Time_out)
        t.start()
        d = int(input("Enter the number\n"))

        if d == c:
            print("Bingo")
            points += 1
            t.cancel()
        elif d != c:
            print("Wrong answer Try again")
            t.cancel()
            #minigame()
        else:
            pass

def sound_arcade_machine():
    print("Seems like arcade machine is broken")
    time.sleep(1.5)
    print("You must be thinking how do i know")
    time.sleep(1.5)
    print("Wait for a while you will also find out")
    time.sleep(1.5)
    print("Embrace your ear")
    time.sleep(1.5)
    for i in range(0, 7):
        Freq = 2500  # Set Frequency To 2500 Hertz
        Dur = 1000 # Set Duration To 1000 ms == 1 second
        winsound.Beep(Freq,Dur)
        time.sleep(0.5)
        Freq = 250 # Set Frequency To 2500 Hertz
        Dur = 1000 # Set Duration To 1000 ms == 1 second
        winsound.Beep(Freq,Dur)
        time.sleep(0.5)
    print("Well...that was LAME...")
    time.sleep(1.5)
def minigame():
    print("There are two games available in your arcade ...")
    print("1. Sum Game('lets see who is stephen hawking':-P)")
    print("2. Typo master(its an beta version with some error)")
    answer = int(input())
    if answer == 1:
        time.sleep(0.5)
        print("Who are you ...a small kid :-P")
        print("Game is loading...please wait for a while...")
        time.sleep(0.5)
        minigame_sum()
    elif answer == 2:
        print("Game is loading...please wait for a while...")
        time.sleep(0.5)
        minigame_word()

def minigame_word():

    print("Enter these words within 6 second...if out of 6")
    print("choose your difficulty\n1.Easy\n2.Medium\n3.Hard\n")
    option1 = int(input())
    if option1 is 1:
        print("Really dude!!!...")
        difficulty(15)
    elif option1 == 2:
        difficulty(8)
    elif option1 == 3:
        difficulty(4)
    else:
        print('Wrong option')
        minigame_word()

   # print("4 answers are correct then you win this minigame")

def difficulty(x):
        points = 0
        word_list = ['mamihlapinatapi', 'liberosis', 'fernweh', 'schlimazel', 'shemomedjamo', 'voopret', 'pteronophobia']
        def Timeout():
            print("\nTimes up")
            print("Your point is \t")
            print(points)
            print("You want to play the minigame again(Y/N)")
            answer = input()
            if answer == 'y' or answer == 'Y':
                minigame()
            elif answer == 'n' or answer == 'n':
                exit()
            else:
                pass

        print("Starts in 2 sec....tighten ur seatbelt :-P")
        time.sleep(2)
        for i in range(0, 7):
            t = Timer(x, Timeout)
            t.start()
            a = random.choice(word_list)
            print("Enter the word :\n")
            print(a)
            b = input()
            if a == b:
                points += 1
                print("Bingo")
                t.cancel()
            else:
                print("too bad")
                t.cancel()

        if i == 6:
            print("Your score is ")
            print(points)
            print("You want to play the minigame again(Y/N)")
            answer = input()
            if answer == 'y' or answer == 'Y':
                minigame()
            elif answer == 'n' or answer == 'n':
                exit()
            else:
                pass


check_value1 = True
check_value2 = True
check_value3 = True

class boolean:
    def zero(self):
        pass
    def first(self):
        global check_value1
        check_value1 = False
    def second(self):
        global check_value2
        check_value2 = False
    def third(self):
        global check_value3
        check_value3 = False

print("  ______               _     _                                       _                      ")
time.sleep(0.4)
print(" |___  /              | |   (_)          /\                         | |                     ")
time.sleep(0.4)
print("    / / ___  _ __ ___ | |__  _  ___     /  \   _ __   ___   ___ __ _| |_   _ _ __  ___  ___ ")
time.sleep(0.4)
print("   / / / _ \| '_ ` _ \| '_ \| |/ _ \   / /\ \ | '_ \ / _ \ / __/ _` | | | | | '_ \/ __|/ _ \ ")
time.sleep(0.4)
print("  / /_| (_) | | | | | | |_) | |  __/  / ____ \| |_) | (_) | (_| (_| | | |_| | |_) \__ \  __/")
time.sleep(0.4)
print(" /_____\___/|_| |_| |_|_.__/|_|\___| /_/    \_\ .__/ \___/ \___\__,_|_|\__, | .__/|___/\___|")
time.sleep(0.4)
print("                                              | |                       __/ | |             ")
time.sleep(0.4)
print("                                              |_|                      |___/|_|             ")

print("This is a story of a young boy....who wakes up one day and finds out that the world he knows have been overthrown ....\nhe lives alone in another city from his mom and dad. After he opened the television he catch up with all the zombie stuffs that have affected some cities ....\nn everyone is requested to visit there nearest airport where rescues to the civilians are being made and so your journey begins")
print("\nNow you are about to leave in your room (you have your inventory empty) \n\n\nNow what you want to do:")
print("\t\t")

ob = boolean()
def home():
    print(" 1.Bedroom\n 2.Bathroom\n 3.Kitchen\n 4.Outside")        #every room can be entered once!!!SORRY FOR THAT INCONVENIENCE
    option1 = int(input())
    if option1 == 1:
        if(check_value1):
            ob.first()
            bedroom()
        else:
            print("You already entered the room once!!!")
            home()
    elif option1 == 2:
        if(check_value2):
            ob.second()
            bathroom()
        else:
            print("You already entered the room once!!!")
            home()
    elif option1 == 3:
        if(check_value3):
            ob.third()
            kitchen()
        else:
            print("You Already entered the room once!!!")
            home()
    elif option1 == 4:
        outside()
    else:
        print("PLEASE ENTER CORRECT OPTION")
        home()

home()