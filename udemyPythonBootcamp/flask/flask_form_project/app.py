from flask import Flask, request, session, redirect, url_for, render_template, flash
from flask_wtf import FlaskForm 
from wtforms import StringField, SubmitField 

app = Flask(__name__)

app.config['SECRET_KEY'] = 'mysectretkey'

class MyForm(FlaskForm):

    fname = StringField("First Name")
    lname = StringField("Last Name")
    #fsport = ("Favourite sports", [()])
    submit = SubmitField("Submit Now")

@app.route('/', methods=['GET', 'POST'])
def index():

    myform = MyForm()
    if myform.validate_on_submit():
        session['fname'] = myform.fname.data
        session['lname'] = myform.lname.data
        #session['fsport'] = myform.fsport.data
        flash('flash is called')
        return redirect(url_for('thankyou'))

    return render_template('index.html',myform=myform)



@app.route('/thankyou')
def thankyou():

    return render_template('thankyou.html')

if __name__ == '__main__':
    app.run()
