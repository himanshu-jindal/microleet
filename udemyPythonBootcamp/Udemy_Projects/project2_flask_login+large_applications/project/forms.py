from flask_wtf import FlaskForm
from wtforms import SubmitField, StringField, PasswordField
from wtforms.validators import DataRequired, Email, EqualTo

class RegistrationForm(FlaskForm):

    username = StringField('Username : ')
    email = StringField('Email : ')
    password = PasswordField('Password : ', validators=[EqualTo('confirm_password')])
    confirm_password = PasswordField('ConfirmPassword : ')
    submit = SubmitField("Register yourself!")

class LoginForm(FlaskForm):

    email = StringField('Email : ')
    password = PasswordField('Password : ')
    submit = SubmitField('Login here : ')