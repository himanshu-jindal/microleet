print("hello")

s = "HIMnahsu"

# strings are immutable

print(s.lower())
print(s.upper)  # address of built in method upper

print(s[::-1])   # start:stop(exclusive):step  , way to reverse string

print(s[:4])  # start default is 0, stop default is last

# string formatting
# f string literals or format method 

print(f"my anme is {s}")


# lists
# pop, insert, append, slicing, nested lists
# ordered 

my_list = [1,2,"him",8, 9,9]

my_list.insert(2,"kylian")

print(my_list)

popped_item = my_list.pop(2)
print(my_list)
print(popped_item)

my_list.append("niraj")

# dictionaries

my_dict = {"himanshu":{"id":1, "goal":"microsoft"}, "shelly":{"id":2, "goal":"good cooking"}}
print(my_dict.keys())
print(my_dict.values())
print(my_dict.items())

# tuples and sets and booleans
# tuples are immutable and same like lists
# sets are unique and unordered

my_tuple = (1,2,"himanshu")

print(my_tuple[0])

my_set = {1,2,3,3,3}
print(my_set)
my_set.add(9)
my_set.add(9)
print(my_set)

print(set(my_list))

print(2>3)

