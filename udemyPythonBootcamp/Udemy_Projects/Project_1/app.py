import os 
from flask import Flask, render_template, redirect, url_for
from flask_sqlalchemy import SQLAlchemy
from flask_migrate import Migrate 
from forms import AddPuppy, AddOwner, DeletePuppy

app = Flask(__name__)


app.config["SECRET_KEY"] = "mysecretkey"
file_path = os.path.abspath(os.path.dirname(__file__))
app.config["SQLALCHEMY_DATABASE_URI"] = 'sqlite:///' + os.path.join(file_path, "data.sqlite")
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False

db = SQLAlchemy(app)
Migrate(app, db)



class Puppy(db.Model):
    __tablename__ = 'puppy'
    name = db.Column(db.String)
    id = db.Column(db.Integer, primary_key=True)
    owner = db.relationship("Owner", backref="Puppy", uselist=False)

    def __init__(self,name):
        self.name = name
    
    def __repr__(self):
        if self.owner:
            return f'Puppy name: {self.name} id: {self.id} and owner is: {self.owner.name} and mob {self.owner.mob}'
        else:
            return f'Puppy name: {self.name} id: {self.id}'


class Owner(db.Model):
    __tablename__ = "owner"
    name = db.Column(db.String)
    id = db.Column(db.Integer, primary_key=True)
    puppy_id = db.Column(db.Integer, db.ForeignKey('puppy.id'))
    mob = db.Column(db.String)
    
    def __init__(self,name, puppy_id, mob):
        self.puppy_id = puppy_id
        self.name = name
        self.mob = mob
    
    def __repr__(self):
        return f'Owner: {self.name} id: {self.id} puppy linked: {self.puppy_id}'




######################################
############## routing ###############
###############################





@app.route('/')
def home():
    return render_template('home.html')

@app.route('/add_puppy', methods=['POST', 'GET'])
def add_puppy():
    form = AddPuppy()
    if form.validate_on_submit():
        puppy_name = form.name.data
        puppy_obj = Puppy(puppy_name)
        db.session.add(puppy_obj)
        db.session.commit()
        print("click is success")
        return redirect(url_for('list_puppy'))
    return render_template('add_puppy.html', form=form)

@app.route('/delete_puppy', methods=['POST', 'GET'])
def delete_puppy():
    form = DeletePuppy()

    if form.validate_on_submit():
        puppy_id = form.id.data
        puppy_obj = Puppy.query.get(puppy_id)
        db.session.delete(puppy_obj)
        db.session.commit()
        return redirect(url_for('list_puppy'))
    return render_template('delete.html', form=form)


@app.route('/list_puppy', methods=['GET', 'POST'])
def list_puppy():
    puppies = Puppy.query.all()
    owners = Owner.query.all()
    return render_template('list.html', puppies=puppies, owners=owners)

@app.route('/add_owner',  methods=['GET', 'POST'])
def add_owner():
    form = AddOwner()
    if form.validate_on_submit():
        owner_name = form.name.data
        puppy_id = form.puppy_id.data
        mob = "9814849537"
        owner_obj = Owner(owner_name, puppy_id, mob)
        db.session.add(owner_obj)
        db.session.commit()
        return redirect(url_for('list_puppy'))

    return render_template('add_owner.html', form=form)


if __name__ == '__main__':

    app.run(debug=True)