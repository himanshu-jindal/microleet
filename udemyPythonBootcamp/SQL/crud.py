from master import db, Student


db.create_all()

# CRUD operations

# create

s2 = Student("palvika", 3)
s3 = Student("shelly",4)

db.session.add_all([s2, s3])
db.session.commit()

# read
# way 1
students_list = Student.query.all()
print(students_list)

# way 2

stud = Student.query.get(1)
print(stud)

# way 3

studs = Student.query.filter_by(year=3)
print(studs.all())

# update

stud = Student.query.get(2)
stud.name = "john sena"
stud.id = 40
db.session.add(stud)
db.session.commit()

print(Student.query.all())

# delete

stud = Student.query.get(1)
db.session.delete(stud)
db.session.commit()
print(Student.query.all())
