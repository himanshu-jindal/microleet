
'''
we need 3 form classes
1) add puppy
2) delete Puppy
3) add owner
'''

from flask_wtf import FlaskForm
from wtforms import StringField, IntegerField, SubmitField

class AddPuppy(FlaskForm):

    name = StringField("Puppy Name:")
    submit = SubmitField("Add Puppy")


class DeletePuppy(FlaskForm):

    id = IntegerField("Id:")
    submit = SubmitField("Remove puppy")

class AddOwner(FlaskForm):

    name = StringField("Owner Name:")
    puppy_id = IntegerField("Puppy Id:")
    submit = SubmitField("Add Owner")


