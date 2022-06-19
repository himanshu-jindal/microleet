import os
from flask import Flask
from flask_sqlalchemy import SQLAlchemy
from flask_migrate import Migrate
from flask_login import LoginManager

# create flask application instance
app = Flask(__name__)


file_path = os.path.abspath(os.path.dirname(__file__))
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
# where to create database file
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///' + os.path.join(file_path, "data.sqlite")
#required to use forms in flask
app.config['SECRET_KEY'] = 'MYSECRETKEY' 

# create flask login manager instance
login_manager = LoginManager()

# create sqlalchemy database
db = SQLAlchemy(app)
# call migrate method
Migrate(app, db)

# flask login association with app
login_manager.init_app(app)
login_manager.login_view = 'login'