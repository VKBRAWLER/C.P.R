import os

print("Welcome to CSE Project Replacement aka CPR 2.0\nPlease Enter your name, section and rollno.")
name = input("Name = ")
sec = input("Section = ")
rollno = input("Roll no. = ")
if rollno == None:
    rollno = 'F'    

path = f'./DMP sheets - VKbrawler/{name}'
os.makedirs(path)

ext = 'c'
for i in range(1,26):
    if i > 22:
        ext = 'py'
    file_name = str(i) + '.' + ext
    with open('./ExCopy/' + file_name, "r") as file:
        text = file.read().replace('RANDOMNAME', name).replace('ABCDEFG', sec).replace('0000000', rollno)
        with open(f'./DMP sheets - VKbrawler/{name}/{file_name}', "w") as file:
            file.write(text)

print(f"Your files is succesfully saved in the directory -> {path}")

print("\n©Copyright VK_BRAWLER aka VARUN KHARKWAL")

# input("\nEnter any key to exit")