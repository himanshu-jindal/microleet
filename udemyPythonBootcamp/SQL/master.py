import os
from flask import Flask
from flask_sqlalchemy import SQLAlchemy

# flask object
app = Flask(__name__)

# file path
file_path = os.path.abspath(os.path.dirname(__file__))

# config setup
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///' + os.path.join(file_path, 'sqlite.data')
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = 'false'

# make database
db = SQLAlchemy(app)

# make model/table
class Student(db.Model):

    __tablename__ = 'Student'

    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String)
    year = db.Column(db.Integer)

    def __init__(self, name, year):
        self.name = name

        self.year = year

    def __repr__(self):

        return f'Student name: {self.name}  and year: {self.year} and id: {self.id}'
