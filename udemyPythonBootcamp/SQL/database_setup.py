from master import db, Student

db.create_all()

student_1 = Student(name="himanshu", year=4)

print(student_1.id)

db.session.add(student_1)
db.session.commit()

print(student_1.id)